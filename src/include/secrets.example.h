// Copy this file to secrets.h and fill in your own AWS IoT Core values.
// secrets.h is gitignored. NEVER commit real certificates or private keys.
#pragma once
#define SECRET
#define THINGNAME "YOUR_THING_NAME"
const char AWS_IOT_ENDPOINT[] = "YOUR-ENDPOINT-ats.iot.REGION.amazonaws.com";

// Amazon Root CA 1 (download from AWS)
static const char AWS_CERT_CA[] = R"EOF(
-----BEGIN CERTIFICATE-----
PASTE_ROOT_CA_HERE
-----END CERTIFICATE-----
)EOF";

// Device certificate
static const char AWS_CERT_CRT[] = R"KEY(
-----BEGIN CERTIFICATE-----
PASTE_DEVICE_CERT_HERE
-----END CERTIFICATE-----
)KEY";

// Device private key
static const char AWS_CERT_PRIVATE[] = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
PASTE_PRIVATE_KEY_HERE
-----END RSA PRIVATE KEY-----
)KEY";
