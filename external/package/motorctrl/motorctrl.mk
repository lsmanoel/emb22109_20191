MOTORCTRL_SITE = $(BR2_EXTERNAL_EMB22109_PATH)/apps/motorctrl
MOTORCTRL_SITE_METHOD=local
MOTORCTRL_DEPENDENCIES = wiringpi

define MOTORCTRL_BUILD_CMDS
	$(TARGET_MAKE_ENV) $(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)
endef

define MOTORCTRL_INSTALL_TARGET_CMDS
	cp -dpf $(@D)/motorctrl $(TARGET_DIR)/usr/bin/

endef

$(eval $(generic-package))
