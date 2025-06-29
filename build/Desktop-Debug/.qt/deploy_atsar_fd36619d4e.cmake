include("/home/nam/Projects/atsar/build/Desktop-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/atsar-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE /home/nam/Projects/atsar/build/Desktop-Debug/atsar
    GENERATE_QT_CONF
)
