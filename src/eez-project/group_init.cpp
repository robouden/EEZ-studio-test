#include "screens.h"

lv_group_t *keypad_group;

static void main_screen_loaded(lv_event_t *e) {
    lv_group_remove_all_objs(keypad_group);

    lv_group_add_obj(keypad_group, objects.page1_button);
    lv_group_add_obj(keypad_group, objects.page2_button);

    lv_group_focus_obj(objects.page1_button);
}

static void page1_screen_loaded(lv_event_t *e) {
    lv_group_remove_all_objs(keypad_group);

    lv_group_add_obj(keypad_group, objects.home_button_1);

    lv_group_focus_obj(objects.home_button_1);
}

static void page2_screen_loaded(lv_event_t *e) {
    lv_group_remove_all_objs(keypad_group);

    lv_group_add_obj(keypad_group, objects.home_button_2);

    lv_group_focus_obj(objects.home_button_2);
}

void ui_init_input_groups() {
    keypad_group = lv_group_create();
    lv_group_set_default(keypad_group);

    lv_obj_add_event_cb(objects.main, main_screen_loaded, LV_EVENT_SCREEN_LOADED, 0);
    lv_obj_add_event_cb(objects.page1, page1_screen_loaded, LV_EVENT_SCREEN_LOADED, 0);
    lv_obj_add_event_cb(objects.page2, page2_screen_loaded, LV_EVENT_SCREEN_LOADED, 0);

    main_screen_loaded(0);
}