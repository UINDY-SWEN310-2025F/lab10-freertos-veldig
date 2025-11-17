#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void taskFirst(void *p) {
    int count = 0;
    while (count < 3) {
        printf("hello task1: count %d\n", count);
        count++;
        vTaskDelay(500 / portTICK_PERIOD_MS);   // 0.5 s
    }
    vTaskDelete(NULL); // terminate this task
}

void taskSecond(void *p) {
    int count = 0;
    while (count < 3) {
        printf("hello task2: count %d\n", count);
        count++;
        vTaskDelay(500 / portTICK_PERIOD_MS);   // 0.5 s
    }
    vTaskDelete(NULL);
}

void taskThird(void *p) {
    int count = 0;
    while (count < 3) {
        printf("hello task3: count %d\n", count);
        count++;
        vTaskDelay(500 / portTICK_PERIOD_MS);   // 0.5 s
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    // create three tasks with different priorities
    // higher number = higher priority
    xTaskCreate(taskFirst,  "Task 1", 2048, NULL, 3, NULL);
    xTaskCreate(taskSecond, "Task 2", 2048, NULL, 2, NULL);
    xTaskCreate(taskThird,  "Task 3", 2048, NULL, 1, NULL);

    // DO NOT block here; let app_main return so you see:
    // "main_task: Returned from app_main()"
}
