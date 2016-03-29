#
#  Copyright 2009 by Texas Instruments Incorporated.
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; version 2 of the License.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>
#
#
-include ../../../Rules.make

# If KERNEL_DIR is not set then use the default in Rules.make
KERNEL_DIR ?= ${LINUXKERNEL_INSTALL_DIR}

# If CROSS_COMPILE is not set by Rules.make then set a sane default
CROSS_COMPILE ?= arm-arago-linux-gnueabi-
export CROSS_COMPILE

# set the INSTALL_MOD_DIR so that the executables won't be placed in extra
INSTALL_MOD_DIR = crypto/ocf
export INSTALL_MOD_DIR

TARGET = ocf_omap3_cryptok.ko

obj-m := ocf_omap3_cryptok.o
ocf_omap3_cryptok-y := ocf_omap3_crypto.o omap3_crypto.o 

MAKE_ENV = ARCH=arm

EXTRA_CFLAGS += -I$(KERNEL_DIR)/crypto/ocf

debug: EXTRA_CFLAGS += -D__DEBUG

.PHONY: clean debug release default install

default: release

docs:

release:
	make -C $(KERNEL_DIR) M=`pwd` $(MAKE_ENV) \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" modules

debug:
	make -C $(KERNEL_DIR) M=`pwd` $(MAKE_ENV) \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" modules

install:
	make -C $(KERNEL_DIR) M=`pwd` $(MAKE_ENV) \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" INSTALL_MOD_PATH="${DESTDIR}" \
		modules_install

clean:
	-rm -rf *.o *mod* *.ko .omap3_crypto* .tmp* Module.symvers
