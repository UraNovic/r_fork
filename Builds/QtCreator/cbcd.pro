
# cbc protocol buffers

PROTOS = ../../src/cbc_data/protocol/cbc.proto
PROTOS_DIR = ../../build/proto

# Google Protocol Buffers support

protobuf_h.name = protobuf header
protobuf_h.input = PROTOS
protobuf_h.output = $${PROTOS_DIR}/${QMAKE_FILE_BASE}.pb.h
protobuf_h.depends = ${QMAKE_FILE_NAME}
protobuf_h.commands = protoc --cpp_out=$${PROTOS_DIR} --proto_path=${QMAKE_FILE_PATH} ${QMAKE_FILE_NAME}
protobuf_h.variable_out = HEADERS
QMAKE_EXTRA_COMPILERS += protobuf_h

protobuf_cc.name = protobuf implementation
protobuf_cc.input = PROTOS
protobuf_cc.output = $${PROTOS_DIR}/${QMAKE_FILE_BASE}.pb.cc
protobuf_cc.depends = $${PROTOS_DIR}/${QMAKE_FILE_BASE}.pb.h
protobuf_cc.commands = $$escape_expand(\\n)
#protobuf_cc.variable_out = SOURCES
QMAKE_EXTRA_COMPILERS += protobuf_cc

# cbc compilation

DESTDIR = ../../build/QtCreator
OBJECTS_DIR = ../../build/QtCreator/obj

TEMPLATE = app
CONFIG += console thread warn_off
CONFIG -= qt gui

DEFINES += _DEBUG

linux-g++:QMAKE_CXXFLAGS += \
    -Wall \
    -Wno-sign-compare \
    -Wno-char-subscripts \
    -Wno-invalid-offsetof \
    -Wno-unused-parameter \
    -Wformat \
    -O0 \
    -std=c++11 \
    -pthread

INCLUDEPATH += \
    "../../src/leveldb/" \
    "../../src/leveldb/port" \
    "../../src/leveldb/include" \
    $${PROTOS_DIR}

OTHER_FILES += \
#   $$files(../../src/*, true) \
#   $$files(../../src/beast/*) \
#   $$files(../../src/beast/modules/beast_basics/diagnostic/*)
#   $$files(../../src/beast/modules/beast_core/, true)

UI_HEADERS_DIR += ../../src/cbc_basics

# ---------
# New style
#
SOURCES += \
    ../../src/cbc/beast/cbc_beast.unity.cpp \
    ../../src/cbc/beast/cbc_beastc.c \
    ../../src/cbc/common/cbc_common.unity.cpp \
    ../../src/cbc/http/cbc_http.unity.cpp \
    ../../src/cbc/json/cbc_json.unity.cpp \
    ../../src/cbc/peerfinder/cbc_peerfinder.unity.cpp \
    ../../src/cbc/radmap/cbc_radmap.unity.cpp \
    ../../src/cbc/resource/cbc_resource.unity.cpp \
    ../../src/cbc/sitefiles/cbc_sitefiles.unity.cpp \
    ../../src/cbc/sslutil/cbc_sslutil.unity.cpp \
    ../../src/cbc/testoverlay/cbc_testoverlay.unity.cpp \
    ../../src/cbc/types/cbc_types.unity.cpp \
    ../../src/cbc/validators/cbc_validators.unity.cpp

# ---------
# Old style
#
SOURCES += \
    ../../src/cbc_app/cbc_app.unity.cpp \
    ../../src/cbc_app/cbc_app_pt1.unity.cpp \
    ../../src/cbc_app/cbc_app_pt2.unity.cpp \
    ../../src/cbc_app/cbc_app_pt3.unity.cpp \
    ../../src/cbc_app/cbc_app_pt4.unity.cpp \
    ../../src/cbc_app/cbc_app_pt5.unity.cpp \
    ../../src/cbc_app/cbc_app_pt6.unity.cpp \
    ../../src/cbc_app/cbc_app_pt7.unity.cpp \
    ../../src/cbc_app/cbc_app_pt8.unity.cpp \
    ../../src/cbc_basics/cbc_basics.unity.cpp \
    ../../src/cbc_core/cbc_core.unity.cpp \
    ../../src/cbc_data/cbc_data.unity.cpp \
    ../../src/cbc_hyperleveldb/cbc_hyperleveldb.unity.cpp \
    ../../src/cbc_leveldb/cbc_leveldb.unity.cpp \
    ../../src/cbc_net/cbc_net.unity.cpp \
    ../../src/cbc_overlay/cbc_overlay.unity.cpp \
    ../../src/cbc_rpc/cbc_rpc.unity.cpp \
    ../../src/cbc_websocket/cbc_websocket.unity.cpp

LIBS += \
    -lboost_date_time-mt\
    -lboost_filesystem-mt \
    -lboost_program_options-mt \
    -lboost_regex-mt \
    -lboost_system-mt \
    -lboost_thread-mt \
    -lboost_random-mt \
    -lprotobuf \
    -lssl \
    -lrt
