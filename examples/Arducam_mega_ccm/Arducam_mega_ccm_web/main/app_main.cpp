#include "who_camera.h"
#include "who_cat_face_detection.hpp"
#include "app_wifi.h"
#include "app_httpd.hpp"
#include "app_mdns.h"

static QueueHandle_t xQueueAIFrame = NULL;
static QueueHandle_t xQueueHttpFrame = NULL;

extern "C" void app_main()
{
    app_wifi_main();
    xQueueHttpFrame = xQueueCreate(2, sizeof(camera_fb_t *));
    register_camera(PIXFORMAT_JPEG, FRAMESIZE_VGA, 1, xQueueHttpFrame);
    app_mdns_main();
    register_httpd(xQueueHttpFrame, NULL, true);
}