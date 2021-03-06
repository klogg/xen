XEN_ROOT=$(CURDIR)/../../..
include $(XEN_ROOT)/tools/Rules.mk

MAJOR = 3.0
MINOR = 3

ifeq ($(CONFIG_Linux),y)
APPEND_LDFLAGS += -ldl
endif

SRCS-y   += xs_lib.c
SRCS-y   += xs.c

LIBHEADER = xenstore.h xenstore_lib.h

include ../libs.mk

# Include configure output (config.h)
CFLAGS += -include $(XEN_ROOT)/tools/config.h
CFLAGS += $(CFLAGS_libxentoolcore)
CFLAGS += -DXEN_LIB_STORED="\"$(XEN_LIB_STORED)\""
CFLAGS += -DXEN_RUN_STORED="\"$(XEN_RUN_STORED)\""

LINK_FILES = xs_lib.c include/xenstore_lib.h list.h utils.h

$(LIB_OBJS): $(LINK_FILES)

$(LINK_FILES):
	ln -sf $(XEN_ROOT)/tools/xenstore/$(notdir $@) $@

xs.opic: CFLAGS += -DUSE_PTHREAD
ifeq ($(CONFIG_Linux),y)
xs.opic: CFLAGS += -DUSE_DLSYM
else
PKG_CONFIG_REMOVE += -ldl
endif

$(PKG_CONFIG_LOCAL): PKG_CONFIG_INCDIR = $(XEN_libxenstore)/include
$(PKG_CONFIG_LOCAL): PKG_CONFIG_CFLAGS_LOCAL = $(CFLAGS_xeninclude)

.PHONY: install
install: install-headers

.PHONY: install-headers
install-headers:
	$(INSTALL_DIR) $(DESTDIR)$(includedir)
	$(INSTALL_DIR) $(DESTDIR)$(includedir)/xenstore-compat
	$(INSTALL_DATA) include/compat/xs.h $(DESTDIR)$(includedir)/xenstore-compat/xs.h
	$(INSTALL_DATA) include/compat/xs_lib.h $(DESTDIR)$(includedir)/xenstore-compat/xs_lib.h
	ln -sf xenstore-compat/xs.h  $(DESTDIR)$(includedir)/xs.h
	ln -sf xenstore-compat/xs_lib.h $(DESTDIR)$(includedir)/xs_lib.h

.PHONY: uninstall
uninstall: uninstall-headers

.PHONY: uninstall-headers
uninstall-headers:
	rm -f $(DESTDIR)$(includedir)/xs_lib.h
	rm -f $(DESTDIR)$(includedir)/xs.h
	rm -f $(DESTDIR)$(includedir)/xenstore-compat/xs_lib.h
	rm -f $(DESTDIR)$(includedir)/xenstore-compat/xs.h
	if [ -d $(DESTDIR)$(includedir)/xenstore-compat ]; then \
		rmdir --ignore-fail-on-non-empty $(DESTDIR)$(includedir)/xenstore-compat; \
	fi
