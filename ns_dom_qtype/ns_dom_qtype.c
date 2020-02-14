#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <resolv.h>
#include <arpa/nameser.h>

int main(int argc, char **argv)
{

    if (argc != 4) {
        fprintf(stderr, "Usage: %s name_server domain qtype\n", argv[0]);
        exit(1);   
    }

    const char* nserver_str = argv[1];
    const char* dom = argv[2];
    const char* qtype_str = argv[3];
    int qtype;
    if(! strcmp(qtype_str, "a")){
        qtype = ns_t_a;
    }else if(! strcmp(qtype_str, "aaaa")){
        qtype = ns_t_aaaa;
    }

    printf("query %s, name_server %s, qtype %s\n",dom, nserver_str, qtype_str);  

    //dns query packet
    u_char buf[NS_PACKETSZ], *data, *rr_in;
    int data_size;
    int buflen ; 
    buflen = res_mkquery(ns_o_query, dom, ns_c_in, qtype, data, data_size, rr_in, buf, NS_PACKETSZ);

    //send query 
    int s = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP); 
    struct sockaddr_in nserver;
    nserver.sin_family = AF_INET;
    nserver.sin_port = htons(NS_DEFAULTPORT);
    nserver.sin_addr.s_addr = inet_addr(nserver_str);
    if( sendto(s, (char*)buf,(size_t)buflen,0,(struct sockaddr*)&nserver,sizeof(nserver)) < 0){
        perror("sendto failed");
    }

    //recv response
    int i = sizeof nserver;
    unsigned char res[NS_MAXMSG];
    int res_maxlen = NS_MAXMSG;
    if(recvfrom (s,(char*)res , res_maxlen, 0 , (struct sockaddr*)&nserver , (socklen_t*)&i ) < 0)
    {
        perror("recvfrom failed");
    }


    //parse answer
    ns_msg msg;
    ns_rr rr;
    char showrr[4096];
    ns_initparse((const u_char *)res, res_maxlen, &msg);
    int l = ns_msg_count (msg, ns_s_an);
    for (int j = 0; j < l; j++) {
        ns_parserr (&msg, ns_s_an, j, &rr);
        ns_sprintrr (&msg, &rr, NULL, NULL, showrr, sizeof (showrr));
        printf ("%s\n", showrr);
    }

    exit(0);
}
