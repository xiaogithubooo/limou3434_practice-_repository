/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.7.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // D:/GitWork/LimouGitWork/limou-c-test-code/my_code_2024_6_13.1/src/App.qml
  
  
    // D:/GitWork/LimouGitWork/limou-c-test-code/my_code_2024_6_13.1/src/logo.ico
  
  
    // D:/GitWork/LimouGitWork/limou-c-test-code/my_code_2024_6_13.1/src/main.qml
  
  
  
static const unsigned char qt_resource_data[121755] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // App.qml
  0x0,0x7,
  0x8,0x73,0x58,0xbc,
  0x0,0x41,
  0x0,0x70,0x0,0x70,0x0,0x2e,0x0,0x71,0x0,0x6d,0x0,0x6c,
    // logo.ico
  0x0,0x8,
  0x5,0xe2,0x41,0xff,
  0x0,0x6c,
  0x0,0x6f,0x0,0x67,0x0,0x6f,0x0,0x2e,0x0,0x69,0x0,0x63,0x0,0x6f,
    // main.qml
  0x0,0x8,
  0x8,0x1,0x5a,0x5c,
  0x0,0x6d,
  0x0,0x61,0x0,0x69,0x0,0x6e,0x0,0x2e,0x0,0x71,0x0,0x6d,0x0,0x6c,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x3,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/logo.ico
  0x0,0x0,0x0,0x14,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x5,0x8e,
0x0,0x0,0x1,0x90,0x11,0xa8,0xe8,0xe1,
  // :/main.qml
  0x0,0x0,0x0,0x2a,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x1,0xd6,0xb4,
0x0,0x0,0x1,0x90,0x11,0xa8,0xe8,0xdb,
  // :/App.qml
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x90,0x15,0x39,0xf4,0x21,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_qml)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_qml)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qml)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qml)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_qml)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qml)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
