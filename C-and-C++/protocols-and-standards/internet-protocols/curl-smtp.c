// send a G-Mail using SMTP

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
 
/* Requirements when compiling

    - OpenSSL with libssl.a and libcrypto.a - (this is included in installation of OpenSSL)
        ./configure --release no-shared
    
    - LibCurl library (the first configuartion I used when installing libcurl)
        ./configure --disable-shared --with-openssl

    - You need a google app password from google, or disable the secure password (this is not available after May 30, 2022)

    compilation : gcc smtp.cpp -o main -lcurl -lssl -lcrypto -O2

 * Note that this example requires libcurl 7.20.0 or above.
 */ 
 
#define FROM    "senders.mail@gmail.com"
#define TO	"receivers.mail@gmail.com"
 
static const char *payload_text[] = {
  "To: " TO "\r\n",
  "From: " FROM "\r\n",
  "Subject: MAIL FROM C PROGRAM\r\n",
  "\r\n", /* empty line to divide headers from body, see RFC5322 */ 
  "At last it worked!!!.\r\n",
  "\r\n",
  "Jesus Christ This one's though setting up.\r\n",
  "I'm now done and out! Bye!.\r\n",
  NULL
};
 
struct upload_status {
  int lines_read;
};
 
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;
 
  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }
 
  data = payload_text[upload_ctx->lines_read];
 
  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;
 
    return len;
  }
 
  return 0;
}
 
int main(void)
{
  CURL *curl;
  CURLcode res = CURLE_OK;
  struct curl_slist *recipients = NULL;
  struct upload_status upload_ctx;
 
  upload_ctx.lines_read = 0;
 
  curl = curl_easy_init();
  
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM);
 
    recipients = curl_slist_append(recipients, TO);
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
 
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
    curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
 
    curl_easy_setopt(curl, CURLOPT_USERNAME, "senders.mail@gmail.com");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "senders-google-app-password");

    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
 
    // you might want to use this next 3 lines of code for windows due to veryfication errors
    // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 0);  // <-- this is to disable veryfication, careful for man in the middle attacks
    // curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem"); // <-- you can download this cacert.pem in libcurl's official website
    // curl_easy_setopt(curl, CURLOPT_CAPATH, "cacert.pem"); //     or maybe OpenSSL? I forgot where I got this .pem, just check the two sites.
	  
    res = curl_easy_perform(curl);
 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    curl_slist_free_all(recipients);
    curl_easy_cleanup(curl);
  }
 
  return (int)res;
}
