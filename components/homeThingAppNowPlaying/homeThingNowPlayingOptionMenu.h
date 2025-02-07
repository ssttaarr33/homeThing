#pragma once

#ifdef USE_MEDIA_PLAYER_GROUP
#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include "esphome/components/display/display_buffer.h"
#include "esphome/components/homeThing/homeThingMenuTitle.h"
#include "esphome/components/homeThing/homeThingOptionMenu.h"
#include "esphome/components/homeThingDisplayState/homeThingDisplayState.h"
#include "esphome/components/homeThingDisplayState/homeThingMenuTextHelpers.h"
#include "esphome/components/homeassistant_media_player/HomeAssistantMediaPlayerGroup.h"

namespace esphome {
namespace homething_menu_now_playing {

class HomeThingMenuNowPlayingOptionMenu {
 public:
  homeassistant_media_player::MediaPlayerFeatureCommand* tap_option_menu(
      CircleOptionMenuPosition position,
      homeassistant_media_player::HomeAssistantBaseMediaPlayer* player);
  void set_active_menu(
      const HomeThingOptionMenuType type,
      homeassistant_media_player::HomeAssistantBaseMediaPlayer* player);
  HomeThingOptionMenu* get_active_menu() { return active_menu_; }
  void clear_active_menu() { active_menu_ = nullptr; }
  void set_bottom_menu(bool bottomMenu) { bottomMenu_ = bottomMenu; }
  bool get_bottom_menu() { return bottomMenu_; }

 private:
  HomeThingOptionMenu* active_menu_{nullptr};

  std::vector<CircleOptionMenuItem> get_supported_feature_options(
      homeassistant_media_player::HomeAssistantBaseMediaPlayer* player);
  const char* const TAG = "homething.menu.option";
  bool bottomMenu_ = false;
};
}  // namespace homething_menu_now_playing
}  // namespace esphome

#endif
