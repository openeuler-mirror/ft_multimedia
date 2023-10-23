# Copyright (c) 2023 Huawei Technologies Co., Ltd. All rights reserved.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set -e

# =============================================================================
# Python
# =============================================================================
#
# check python3 in current system.
PYTHON_REQUIRED_VERSION="3.9.2"

echo -e "\e[36m[-] Prepare python3 packages...\e[0m"

# Check if python3 is installed
if ! command -v python3 &> /dev/null; then
    echo "python3 is not installed"
    exit 1
fi
if ! command -v pip3 &> /dev/null; then
    echo "pip3 is not installed"
    exit 1
fi

# Check python version
PYTHON_VERSION=$(python3 --version 2>&1 | awk '{print $2}')

# Compare the versions
if [ "$(printf '%s\n' "$PYTHON_REQUIRED_VERSION" "$PYTHON_VERSION" | sort -V | head -n1)" = "$PYTHON_REQUIRED_VERSION" ]; then
    echo "The python3 version is $PYTHON_VERSION"
else
    echo "The python3 version is less than $PYTHON_REQUIRED_VERSION"
fi

# Install python packages
SCRIPT_DIR=$(cd $(dirname $0);pwd)
PROJECT_DIR=$(dirname ${SCRIPT_DIR})

pip3 install -r ${SCRIPT_DIR}/configs/requirements.txt

# =============================================================================
# System Packages
# =============================================================================
#
# check system packages in current system by calling builder.py

echo -e "\e[36m[-] Prepare system packages...\e[0m"

# Check & Install required system packages
python3 ${PROJECT_DIR}/build/builder.py check --install-packages

# =============================================================================
# Prebuild
# =============================================================================
#
# download prebuild files
cd $home
PREBUILD_DIR="ft_prebuild"
if [ ! -d ${PREBUILD_DIR} ]; then
mkdir ${PREBUILD_DIR}
fi
cd ${PREBUILD_DIR}
FT_PREBUILD_DIR=$(pwd)

ARCHNAME=`uname -m`

if [ ! -e /usr/lib64/libace_skia_fangtian.so ]; then
    echo "start build libace_skia_fangtian.so"
    if [ ! -d ${PROJECT_DIR}/third_party/ft_flutter ]; then
        git clone -b 2203sp2_20231023 https://gitee.com/openeuler/ft_flutter.git ${PROJECT_DIR}/third_party/ft_flutter
        cd ${PROJECT_DIR}/third_party/ft_flutter
        git fetch https://gitee.com/openeuler/ft_flutter.git pull/24/head:pr_24
        ./project_build/prebuild.sh
    fi
    cd ${PROJECT_DIR}/third_party/ft_flutter
    ./build.sh $*
    cd ${PROJECT_DIR}
fi

# copy config files to /usr/local/share/ft/multimedia/image
sudo mkdir -p /usr/local/share/ft/multimedia/image
sudo cp ${PROJECT_DIR}/image_framework/plugins/common/libs/image/libpngplugin/pngplugin.pluginmeta /usr/local/share/ft/multimedia/image
sudo cp ${PROJECT_DIR}/image_framework/plugins/common/libs/image/libjpegplugin/jpegplugin.pluginmeta /usr/local/share/ft/multimedia/image
sudo cp ${PROJECT_DIR}/image_framework/plugins/common/libs/image/formatagentplugin/imageformatagent.pluginmeta /usr/local/share/ft/multimedia/image
sudo cp ${PROJECT_DIR}/image_framework/plugins/common/libs/image/librawplugin/rawplugin.pluginmeta /usr/local/share/ft/multimedia/image
sudo cp ${PROJECT_DIR}/image_framework/plugins/common/libs/image/libbmpplugin/bmpplugin.pluginmeta /usr/local/share/ft/multimedia/image
sudo cp ${PROJECT_DIR}/image_framework/plugins/common/libs/image/libwebpplugin/webpplugin.pluginmeta /usr/local/share/ft/multimedia/image
sudo cp ${PROJECT_DIR}/image_framework/plugins/common/libs/image/libgifplugin/gifplugin.pluginmeta /usr/local/share/ft/multimedia/image

echo -e "\033[32m[*] Pre-build Done. You need exec 'build.sh'.\033[0m"
