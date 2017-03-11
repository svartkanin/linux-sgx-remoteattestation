#ifndef GENERALSETTINGS_H
#define GENERALSETTINGS_H

#include <string>

using namespace std;

namespace Settings {
	static int rh_port = 22222;
	static string rh_host = "localhost";
	
	static string server_crt = ""; //certificate for the HTTPS connection between the SP and the App
	static string server_key = ""; //private key for the HTTPS connection

	static string spid = ""; //SPID provided by Intel after registration for the IAS service
	static const char *ias_crt = ""; //location of the certificate send to Intel when registring for the IAS
	static string ias_url = "https://test-as.sgx.trustedservices.intel.com:443/attestation/sgx/v1/";
}

#endif
