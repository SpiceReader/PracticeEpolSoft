TEMPLATE = subdirs

SUBDIRS += \
    Network \
    Server\
    Client

# build the project sequentially as listed in SUBDIRS !
CONFIG += ordered

Client.depends = Network
Server.depends = Network
