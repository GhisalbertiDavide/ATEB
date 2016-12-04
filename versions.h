#ifndef VERSIONS_H
#define VERSIONS_H

/** Versions list **/
#define MAIN_VERSION "0.0.1-alpha"

//Version of RS232 Handler module
//#define RS232HANDLER_VERSION "0.0.0"

//Version of Ethernet handler module
//#define ETHERNET_VERSION "0.0.0"

/** Config file paths **/
#define MAIN_CONFIG "config/main.conf"
#ifdef RS232HANDLER_VERSION
#define RS232_CONFIG "config/rs232.conf"
#endif
#ifdef ETHERNET_VERSION
#define ETHERNET_CONFIG "config/eth.conf"
#endif


/** Utility macros **/
#define itostr(A) QString::number(A)

#endif // VERSIONS_H
