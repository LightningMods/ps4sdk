#these export a similarly named make variable
# all syscalls here
include $(CURDIR)/systemcalls.mk
# all kernel functions here
include $(CURDIR)/kerns.mk
# all libcinternal functions here
include $(CURDIR)/libcinternals.mk
# all libc functions here
#include $(CURDIR)/libcs.mk
# all libkernel functions here
include $(CURDIR)/libkernels505.mk
# all piglet and gl es functions here
include $(CURDIR)/libScePigletv2VSH.mk

# we externalize these three because of size and to generate adaptive libs
$(eval $(call generateModuleLarge, libSceLibcInternal, $(libCInternals)))
#$(eval $(call generateModule, libc, $(libcs)))
$(eval $(call generateModule, libkernel, $(libKernels)))
$(eval $(call generateModuleLarge, libScePigletv2VSH, $(libScePigletv2VSH)))

# all plain modules and symbols here
$(eval $(call generateModule, libSceCamera, sceCameraAudioOpen sceCameraClose sceCameraCloseByHandle sceCameraGetAttribute sceCameraGetAutoExposureGain sceCameraGetAutoWhiteBalance sceCameraGetCalibrationData sceCameraGetConfig sceCameraGetContrast sceCameraGetDefectivePixelCancellation sceCameraGetDeviceInfo sceCameraGetExposureGain sceCameraGetFrameData sceCameraGetGamma sceCameraGetHue sceCameraGetLensCorrection sceCameraGetSaturation sceCameraGetSharpness sceCameraGetWhiteBalance sceCameraIsAttached sceCameraIsValidFrameData sceCameraOpen sceCameraOpenByModuleId sceCameraSetAttribute sceCameraSetAutoExposureGain sceCameraSetAutoWhiteBalance sceCameraSetCalibData sceCameraSetConfig sceCameraSetConfigInternal sceCameraSetContrast sceCameraSetDefectivePixelCancellation sceCameraSetExposureGain sceCameraSetGamma sceCameraSetHue sceCameraSetLensCorrection sceCameraSetSaturation sceCameraSetSharpness sceCameraSetWhiteBalance sceCameraStart sceCameraStartByHandle sceCameraStop sceCameraStopByHandle))
$(eval $(call generateModule, libSceNet, sceNetAccept sceNetBind sceNetConnect sceNetGetsockname sceNetGetsockopt sceNetHtonl sceNetHtonll sceNetHtons sceNetInetNtop sceNetInetPton sceNetListen sceNetNtohl sceNetNtohll sceNetNtohs sceNetRecv sceNetSend sceNetSetsockopt sceNetSocket sceNetSocketAbort sceNetSocketClose))
$(eval $(call generateModule, libScePad, scePadClose scePadInit scePadOpen scePadRead scePadReadState))
$(eval $(call generateModule, libSceSysmodule, sceSysmoduleIsLoaded sceSysmoduleLoadModule sceSysmoduleUnloadModule))
$(eval $(call generateModule, libSceUsbd, sceUsbdBulkTransfer sceUsbdCheckConnected sceUsbdClearHalt sceUsbdClose sceUsbdControlTransfer sceUsbdExit sceUsbdFreeConfigDescriptor sceUsbdFreeDeviceList sceUsbdGetActiveConfigDescriptor sceUsbdGetConfigDescriptor sceUsbdGetConfigDescriptorByValue sceUsbdGetDeviceDescriptor sceUsbdGetDeviceList sceUsbdInit sceUsbdInterruptTransfer sceUsbdOpen sceUsbdOpenDeviceWithVidPid sceUsbdResetDevice sceUsbdSetInterfaceAltSetting))
$(eval $(call generateModule, libSceUserService, sceUserServiceInitialize sceUserServiceTerminate sceUserServiceGetLoginUserIdList sceUserServiceGetEvent sceUserServiceGetInitialUser sceUserServiceGetUserName sceUserServiceGetUserColor))
$(eval $(call generateModule, libSceVideoOut, sceVideoOutOpen sceVideoOutClose sceVideoOutRegisterBuffers sceVideoOutUnregisterBuffers sceVideoOutSubmitFlip sceVideoOutSetBufferAttribute sceVideoOutSetFlipRate sceVideoOutAddFlipEvent sceVideoOutGetFlipStatus))
$(eval $(call generateModule, libSceGnmDriver, sceGnmFlushGarlic))
$(eval $(call generateModule, libSceSystemService, sceSystemServiceHideSplashScreen))
$(eval $(call generateModule, libSceAudioOut, sceAudioOutInit sceAudioOutOpen sceAudioOutClose sceAudioOutOutput sceAudioOutSetVolume))
$(eval $(call generateModule, libSceIme, sceImeKeyboardOpen sceImeKeyboardClose sceImeKeyboardUpdate sceImeKeyboardGetInfo sceImeKeyboardSetMode sceImeKeyboardGetResourceId sceImeUpdate sceImeOpen sceImeClose sceImeParamInit sceImeSetText))
$(eval $(call generateModule, libSceHttp, sceHttpAbortRequest sceHttpAbortRequestForce sceHttpAbortWaitRequest sceHttpAddCookie sceHttpAddRequestHeader sceHttpAddRequestHeaderRaw sceHttpAuthCacheExport sceHttpAuthCacheFlush sceHttpAuthCacheImport sceHttpCookieExport sceHttpCookieFlush sceHttpCookieImportsceHttpCreateConnection sceHttpCreateConnectionWithURL sceHttpCreateEpoll sceHttpCreateRequest sceHttpCreateRequest2 sceHttpCreateRequestWithURL sceHttpCreateRequestWithURL2 sceHttpCreateTemplate sceHttpDbgEnableProfile sceHttpDbgGetConnectionStat sceHttpDbgGetRequestStat sceHttpDbgSetPrintf sceHttpDbgShowConnectionStat sceHttpDbgShowMemoryPoolStat sceHttpDbgShowRequestStat sceHttpDbgShowStat sceHttpDeleteConnection sceHttpDeleteRequest sceHttpDeleteTemplate sceHttpDestroyEpoll sceHttpGetAcceptEncodingGZIPEnabled sceHttpGetAllResponseHeaders sceHttpGetAuthEnabled sceHttpGetAutoRedirect sceHttpGetConnectionStat sceHttpGetCookie sceHttpGetCookieEnabled sceHttpGetCookieStats sceHttpGetCookieStats sceHttpGetEpollId sceHttpGetLastErrno sceHttpGetMemoryPoolStats sceHttpGetNonblock sceHttpGetResponseContentLength sceHttpGetStatusCode sceHttpInit sceHttpParseResponseHeader sceHttpParseStatusLine sceHttpReadData sceHttpRedirectCacheFlush sceHttpRemoveRequestHeader sceHttpRequestGetAllHeaders sceHttpsDisableOption sceHttpsDisableOptionPrivate sceHttpsEnableOption sceHttpsEnableOptionPrivate sceHttpSendRequest sceHttpSetAcceptEncodingGZIPEnabled sceHttpSetAuthEnabled sceHttpSetAuthInfoCallback sceHttpSetAutoRedirect sceHttpSetChunkedTransferEnabled sceHttpSetConnectTimeOut sceHttpSetCookieEnabled sceHttpSetCookieMaxNum sceHttpSetCookieMaxNumPerDomain sceHttpSetCookieMaxSize sceHttpSetCookieRecvCallback sceHttpSetCookieSendCallback sceHttpSetCookieTotalMaxSize sceHttpSetDefaultAcceptEncodingGZIPEnabled sceHttpSetEpoll sceHttpSetEpollId sceHttpSetHttp09Enabled sceHttpSetInflateGZIPEnabled sceHttpSetNonblock sceHttpSetPolicyOption sceHttpSetPriorityOption sceHttpSetProxy sceHttpSetRecvBlockSize  sceHttpSetRecvTimeOut sceHttpSetRedirectCallback sceHttpSetRequestContentLength sceHttpSetRequestStatusCallback sceHttpSetResolveRetry sceHttpSetResolveTimeOut sceHttpSetResponseHeaderMaxSize sceHttpSetSendTimeOut sceHttpsFreeCaList sceHttpsGetCaList sceHttpsGetSslError sceHttpsLoadCert sceHttpsSetSslCallback sceHttpsSetSslVersion sceHttpsUnloadCert sceHttpTerm sceHttpTryGetNonblock sceHttpTrySetNonblock sceHttpUnsetEpoll sceHttpUriBuild sceHttpUriCopy sceHttpUriEscape sceHttpUriMerge sceHttpUriParse sceHttpUriSweepPath sceHttpUriUnescape sceHttpWaitRequest))


# no need to touch, generates non-module libs
$(eval $(call generateLibraryLarge, kern_function, libps4Kernel, none, $(kerns)))
$(eval $(call generateLibrary, system_call, libPs4SystemCall, none, $(systemcalls)))

# adaptive libs
$(eval $(call generateLibrary, adaptive_system_call, libPs4SystemCallAdaptive, none, $(sort $(filter $(systemcalls),$(kerns)))))
$(eval $(call generateLibrary, adaptive_function, libPs4LibCInternalAdaptive, libSceLibcInternal, $(sort $(filter $(libCInternals),$(kerns)))))
#$(eval $(call generateLibrary, adaptive_function, libcAndKernel, libc, $(sort $(filter $(libc),$(kerns)))))
$(eval $(call generateLibrary, adaptive_function, libPs4LibKernelAdaptive, libkernel, $(sort $(filter $(libKernels),$(kerns)))))
