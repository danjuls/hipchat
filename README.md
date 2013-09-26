hipchat-drupal7
===============

Hipchat for Drupal 7
Original module is found for Drupal 6 at https://drupal.org/project/hipchat

## Installation
After installing this module as normal you need to:

- 1) Add an admin API Token from HipChat and the default room to receive messages at /admin/config/services/hipchat (configure link is present on module page).
- 2) On hipchat settingspage choose what contenttypes should be active and if comments should be active for choosen contenttype.
- 3) Download the hipchat-php library from github - https://github.com/hipchat/hipchat-php and place it at path/to/hipchat/hipchat-php

## Checklist for D6 to D7 version of module.
- [x] Fix bug with PHP namespace when using newer version of hipchat-php.
- [x] Add ability to change message color sent to Hipchat.
- [x] Give user the choice on what contenttypes add,update and delete for nodes and comments should work.
- [] When adding apikey and room name send test message to room. 
