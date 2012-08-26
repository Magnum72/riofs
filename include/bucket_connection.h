#include "include/global.h"

typedef enum {
    RT_list = 0,
} RequestType;


BucketConnection *bucket_connection_new (Application *app, S3Bucket *bucket);
void bucket_connection_destroy (BucketConnection *con);

struct evhttp_connection *bucket_connection_get_evcon (BucketConnection *con);
S3Bucket *bucket_connection_get_bucket (BucketConnection *con);
Application *bucket_connection_get_app (BucketConnection *con);

gboolean bucket_connection_connect (BucketConnection *con);

void bucket_connection_send (BucketConnection *con, struct evbuffer *outbuf);


const gchar *bucket_connection_get_auth_string (BucketConnection *con, 
        const gchar *method, const gchar *content_type, const gchar *resource);
struct evhttp_request *bucket_connection_create_request (BucketConnection *con,
    void (*cb)(struct evhttp_request *, void *), void *arg,
    const gchar *auth_str);


gboolean bucket_connection_get_directory_listing (BucketConnection *con, const gchar *path);