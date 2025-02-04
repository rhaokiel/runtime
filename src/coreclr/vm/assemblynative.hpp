// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

/*============================================================
**
** Header:  AssemblyNative.hpp
**
** Purpose: Implements FCalls for managed Assembly class
**
**


**
===========================================================*/
#ifndef _ASSEMBLYNATIVE_H
#define _ASSEMBLYNATIVE_H

class CustomAssemblyBinder;

class AssemblyNative
{
    friend class Assembly;
    friend class BaseDomain;
    friend class DomainAssembly;

public:
    // static FCALLs
    static
    void QCALLTYPE GetEntryAssembly(QCall::ObjectHandleOnStack retAssembly);

    static
    void QCALLTYPE GetExecutingAssembly(QCall::StackCrawlMarkHandle stackMark, QCall::ObjectHandleOnStack retAssembly);

    static FCDECL0(FC_BOOL_RET, IsTracingEnabled);

    //
    // instance FCALLs
    //

    static
    void QCALLTYPE GetLocale(QCall::AssemblyHandle pAssembly, QCall::StringHandleOnStack retString);

    static
    INT32 QCALLTYPE GetHashAlgorithm(QCall::AssemblyHandle pAssembly);


    static
    void QCALLTYPE GetSimpleName(QCall::AssemblyHandle pAssembly, QCall::StringHandleOnStack retSimpleName);

    static
    void QCALLTYPE GetPublicKey(QCall::AssemblyHandle pAssembly, QCall::ObjectHandleOnStack retPublicKey);

    static
    INT32 QCALLTYPE GetFlags(QCall::AssemblyHandle pAssembly);

    static
    void QCALLTYPE GetFullName(QCall::AssemblyHandle pAssembly, QCall::StringHandleOnStack retString);

    static
    void QCALLTYPE GetLocation(QCall::AssemblyHandle pAssembly, QCall::StringHandleOnStack retString);

    static
    BOOL QCALLTYPE GetCodeBase(QCall::AssemblyHandle pAssembly, QCall::StringHandleOnStack retString);

    static
    BYTE * QCALLTYPE GetResource(QCall::AssemblyHandle pAssembly, LPCWSTR wszName, DWORD * length);

    static
    FCDECL1(FC_BOOL_RET, IsDynamic, AssemblyBaseObject * pAssemblyUNSAFE);

    static
    void QCALLTYPE GetVersion(QCall::AssemblyHandle pAssembly, INT32* pMajorVersion, INT32* pMinorVersion, INT32*pBuildNumber, INT32* pRevisionNumber);

    static
    void QCALLTYPE GetType(QCall::AssemblyHandle pAssembly, LPCWSTR wszName, BOOL bThrowOnError, BOOL bIgnoreCase, QCall::ObjectHandleOnStack retType, QCall::ObjectHandleOnStack keepAlive, QCall::ObjectHandleOnStack pAssemblyLoadContext);

    static
    void QCALLTYPE GetForwardedType(QCall::AssemblyHandle pAssembly, mdToken mdtExternalType, QCall::ObjectHandleOnStack retType);

    static
    INT32 QCALLTYPE GetManifestResourceInfo(QCall::AssemblyHandle pAssembly, LPCWSTR wszName, QCall::ObjectHandleOnStack retAssembly, QCall::StringHandleOnStack retFileName);

    static
    void QCALLTYPE GetModules(QCall::AssemblyHandle pAssembly, BOOL fLoadIfNotFound, BOOL fGetResourceModules, QCall::ObjectHandleOnStack retModules);

    static
    void QCALLTYPE GetModule(QCall::AssemblyHandle pAssembly, LPCWSTR wszFileName, QCall::ObjectHandleOnStack retModule);

    static
    void QCALLTYPE GetExportedTypes(QCall::AssemblyHandle pAssembly, QCall::ObjectHandleOnStack retTypes);

    static
    void QCALLTYPE GetForwardedTypes(QCall::AssemblyHandle pAssembly, QCall::ObjectHandleOnStack retTypes);

    static FCDECL1(Object*, GetManifestResourceNames, AssemblyBaseObject * pAssemblyUNSAFE);
    static FCDECL1(Object*, GetReferencedAssemblies, AssemblyBaseObject * pAssemblyUNSAFE);

    static
    void QCALLTYPE GetEntryPoint(QCall::AssemblyHandle pAssembly, QCall::ObjectHandleOnStack retMethod);

    static FCDECL1(ReflectModuleBaseObject *, GetInMemoryAssemblyModule, AssemblyBaseObject * pAssemblyUNSAFE);

    static
    void QCALLTYPE GetImageRuntimeVersion(QCall::AssemblyHandle pAssembly, QCall::StringHandleOnStack retString);

    static BOOL QCALLTYPE GetIsCollectible(QCall::AssemblyHandle pAssembly);

    static FCDECL0(uint32_t, GetAssemblyCount);

    //
    // PEAssembly QCalls
    //

    static INT_PTR QCALLTYPE InitializeAssemblyLoadContext(INT_PTR ptrManagedAssemblyLoadContext, BOOL fRepresentsTPALoadContext, BOOL fIsCollectible);
    static void QCALLTYPE PrepareForAssemblyLoadContextRelease(INT_PTR ptrNativeAssemblyBinder, INT_PTR ptrManagedStrongAssemblyLoadContext);
    static void QCALLTYPE InternalLoad(QCall::ObjectHandleOnStack assemblyName, QCall::ObjectHandleOnStack requestingAssembly, QCall::StackCrawlMarkHandle stackMark,BOOL fThrowOnFileNotFound, QCall::ObjectHandleOnStack assemblyLoadContext, QCall::ObjectHandleOnStack retAssembly);
    static void QCALLTYPE LoadFromPath(INT_PTR ptrNativeAssemblyBinder, LPCWSTR pwzILPath, LPCWSTR pwzNIPath, QCall::ObjectHandleOnStack retLoadedAssembly);
    static void QCALLTYPE LoadFromStream(INT_PTR ptrNativeAssemblyBinder, INT_PTR ptrAssemblyArray, INT32 cbAssemblyArrayLength, INT_PTR ptrSymbolArray, INT32 cbSymbolArrayLength, QCall::ObjectHandleOnStack retLoadedAssembly);
#ifndef TARGET_UNIX
    static void QCALLTYPE LoadFromInMemoryModule(INT_PTR ptrNativeAssemblyBinder, INT_PTR hModule, QCall::ObjectHandleOnStack retLoadedAssembly);
#endif
    static Assembly* LoadFromPEImage(AssemblyBinder* pBinder, PEImage *pImage);
    static INT_PTR QCALLTYPE GetLoadContextForAssembly(QCall::AssemblyHandle pAssembly);

    static BOOL QCALLTYPE InternalTryGetRawMetadata(QCall::AssemblyHandle assembly, UINT8 **blobRef, INT32 *lengthRef);
    static void QCALLTYPE TraceResolvingHandlerInvoked(LPCWSTR assemblyName, LPCWSTR handlerName, LPCWSTR alcName, LPCWSTR resultAssemblyName, LPCWSTR resultAssemblyPath);
    static void QCALLTYPE TraceAssemblyResolveHandlerInvoked(LPCWSTR assemblyName, LPCWSTR handlerName, LPCWSTR resultAssemblyName, LPCWSTR resultAssemblyPath);
    static void QCALLTYPE TraceAssemblyLoadFromResolveHandlerInvoked(LPCWSTR assemblyName, bool isTrackedAssembly, LPCWSTR requestingAssemblyPath, LPCWSTR requestedAssemblyPath);
    static void QCALLTYPE TraceSatelliteSubdirectoryPathProbed(LPCWSTR filePath, HRESULT hr);

    static void QCALLTYPE ApplyUpdate(QCall::AssemblyHandle assembly, UINT8* metadataDelta, INT32 metadataDeltaLength, UINT8* ilDelta, INT32 ilDeltaLength, UINT8* pdbDelta, INT32 pdbDeltaLength);
    static BOOL QCALLTYPE IsApplyUpdateSupported();
};

#endif

