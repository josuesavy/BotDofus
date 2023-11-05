# How to Build OpenSSL, zlib, and cURL libraries on Windows
OpenSSL, zlib, and cURL are open-source computer software projects to secure communications over computer networks, compress data, and transfer data through various network protocols, respectively. The projects are comprised of command-line tools, header files, and libraries. They are widely used by many systems, applications, and libraries including Refinitiv Real-Time SDK C/C++. Users can utilize available OpenSSL, zlib, and cURL libraries available on the Internet or build the latest versions of those libraries from the source code.

Refinitiv Real-Time SDK C/C++ is a suite of modern and open-source APIs that is designed to simplify development through a strong focus on ease of use and standardized access to a broad set of Refinitiv and proprietary content and services. It uses these libraries to connect to encrypted servers or Refinitiv Real-Time Optimized on the cloud.

This article demonstrates step by step to build OpenSSL, zlib, and cURL libraries from the source code on a Windows machine (Windows 10). Then, it shows how to use these libraries in Refinitiv Real-Time SDK C/C++. The topics include:

-   Build OpenSSL Libraries
-   Build zlib libraries
-   Build cURL Libraries
-   Use the Libraries with Refinitiv Real-Time SDK C/C++

## Prerequisites

To follow the steps in this article, you need to have a Windows 10 machine with the following applications installed.

1.  **Microsoft Visual Studio:**  Desktop Development with C++ (such as, Visual Studio 2019 or 2022)
2.  [**Strawberry Perl**](https://strawberryperl.com/)**:**  A perl environment for Microsoft Windows (Required to build OpenSSL)
3.  [**Netwide Assembler**](https://www.nasm.us/) **(NASM):**  An assembler for the x86 CPU architecture (Required to build OpenSSL)
4.  A decompression tool, such as WinRAR

## Build OpenSSL Libraries

OpenSSL is a software library implementing the SSL and TLS protocols for applications that secure communications over computer networks. It is widely used by Internet servers, including the majority of HTTPS websites. It contains two libraries which are libssl and libcrypto. The libcrypto library provides the fundamental cryptographic routines used by libssl.

The following steps show how to build the OpenSSL libraries and a binary file from the OpenSSL source package on a Windows 10 machine.

**1. Download and decompress the OpenSSL source code package**

The OpenSSL is open source and the source code is available on the OpenSSL official website ([https://www.openssl.org](https://www.openssl.org/)). At the time of this writing, the current versions of the OpenSSL packages are  **openssl-1.1.1o**  and  **openssl-3.0.3**.  

I will download the  **openssl-1.1.1o**  package but the steps mentioned in this article can also be used with the  **openssl-3.0.3**  package.

First, download the OpenSSL source package (**openssl-1.1.1o.tar.gz**) and decompress it to the local directory, such as  **C:\local\src**.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_folder.png.transform/resize-768/q82/image.png)

**2. Configure the package**

To follow this step, the Perl and NASM directory must be added to the  **Path**  environment variable.  

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_path.png.transform/resize-768/q82/image.png)

You can test it my running “**perl -v**” and “**nasm -v**” on the command prompt.

```

```

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_perl_nasm.png.transform/resize-768/q82/image.png)

From the previous step, all files are extracted in the  **openssl-1.1.1.o**  directory. Run the  **x64 Native Tools Command Prompt for Visual Studio**  and then change the directory to  **C:\local\src\ openssl-1.1.1.o**.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_cmd.png.transform/resize-768/q82/image.png)

Then, run the  **config**  command to configure the OpenSSL source package.

```
perl Configure VC-WIN64A --prefix=c:\local\openssl1.1.1
```

I ran the  **Configure** command with the following options.

**Option**

**Description**

--prefix= c:\local\openssl1.1.1

The top of the installation directory tree. The OpenSSL libraries will be created in this directory (c:\local\openssl1.1.1)

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_configure.png.transform/resize-768/q82/image.png)

For other options, please refer to the  **INSTALL**  file in the OpenSSL source package.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_install.png.transform/resize-768/q82/image.png)

**3. Build the OpenSSL libraries**

Run the  **nmake**  command to build the OpenSSL libraries (libcrypto and libssl) and the OpenSSL binary (openssl).

```
nmake
```

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_nmake.png.transform/resize-768/q82/image.png)

The libraries will be built in the top-level directory, and the binary will be in the  **apps**  subdirectory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_libraries.png.transform/resize-768/q82/image.png)

Finally, run the “**nmake install**” command to install OpenSSL on the machine.

```
nmake install
```

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_nmake_install.png.transform/resize-768/q82/image.png)

The command will install all the OpenSSL components in the directory specified in the  **--prefix**  option (**C:\local\openssl1.1.1**). OpenSSL configuration files are in the  **C:\Program Files\Common Files\SSL**  directory.

The libraries are in the  **C:\local\openssl1.1.1\lib**  and  **C:\local\openssl1.1.1\bin** directory and the OpenSSL binary file is in the  **C:\local\openssl1.1.1\bin** directory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_lib_dir.png.transform/resize-768/q82/image.png)

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/ssl_bin_dir.png.transform/resize-768/q82/image.png)

At this point, the OpenSSL binary and library files are built properly.

## Build zlib Libraries

Zlib is a free and general-purpose lossless data-compression software library for use on any computer hardware and software platform, including Linux, macOS, and Windows. The zlib data format is itself portable across platforms. The following steps demonstrate how to build zlib libraries from the zlib source package on a Windows 10 machine.

**1. Download and decompress the zlib source code package**

Zlib is open source and the source code is available on the zlib official website ([https://zlib.net/](https://zlib.net/)). At the time of this writing, the current version of the zlib package is zlib-1.2.12. Download the zlib source package (zlib-1.2.12.tar.gz) and decompress it to the local directory, such as  **C:\local\src**.  

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/zlib_folder.png.transform/resize-768/q82/image.png)

**2. Build the zlib libraries**

From the previous step, all files are extracted in the  **zlib-1.2.12**  directory. Run the  **x64 Native Tools Command Prompt for Visual Studio**  and then change the directory to  **C:\local\src\zlib-1.2.12**.  

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/zlib_cmd.png.transform/resize-768/q82/image.png)

Then, run the  **nmake**  command to build the zlib libraries.

```
nmake /f win32/Makefile.msc
```

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/zlib_nmake.png.transform/resize-768/q82/image.png)

The following files will be created in the  **C:\local\src\zlib-1.2.12**  directory.

-   **zlib.lib:**  A zlib static library
-   **zlib.pdb:** A  program database file of zlib.lib
-   **zdll.lib:** An import library of zlib1.dll
-   **zlib1.dll:**  A zlib shared library
-   **zlib1.pdb:**  A program database of zlib1.dll

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/zlib_libraries.png.transform/resize-768/q82/image.png)

**3. Copy zlib files**

In this step, the zlib header files and library files will be copied to the new zlib folder. First, create a new folder for zlib files, such as  **C:\local\zlib**.  

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/zlib_local.png.transform/resize-768/q82/image.png)

Then,  **copy zlib.h**  and  **zconf.h**  files from  **C:\local\src\zlib-1.2.12**  to  **C:\local\zlib\include**.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/zlib_local_include.png.transform/resize-768/q82/image.png)

Finally, copy the zlib library files from  **C:\local\src\zlib-1.2.12**  to  **C:\local\zlib\lib**  directory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/zlib_local_lib.png.transform/resize-768/q82/image.png)

At this point, the zlib library files are built properly.

## Build cURL Library

cURL is a computer software project providing a library and a command-line tool for transferring data using various network protocols. It builds and works identically on many platforms. cURL supports HTTPS and performs SSL certificate verification by default when a secure protocol is specified such as HTTPS. It relies on the OpenSSL libraries to perform SSL certificate verification.

The following steps show how to build a cURL library and cURL binary file from the cURL source package on a Windows 10 machine. Moreover, the cURL library and cURL binary file will use the zlib and OpenSSL libraries created in the previous sections.

**1. Download and decompress the cURL source code package**

cURL is open source and the source code is available on the cURL official website (https://curl.se/download.html). At the time of this writing, the current version of the cURL package is  **curl-7.83.1**.  

First, download the cURL source package (**curl-7.83.1.tar.gz**) and decompress it to the local directory, such as  **C:\local\src**.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_package.png.transform/resize-768/q82/image.png)

**2. Build the cURL libraries**

From the previous step, all files are extracted in the  **curl-7.83.1**  directory. Run the  **x64 Native Tools Command Prompt for Visual Studio**  and then change the directory to  **C:\local\src\curl-7.83.1**\**winbuild**.  

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_cmd.png.transform/resize-768/q82/image.png)

cURL supports many underlying protocols. We can configure it when building the libraries. The following section demonstrates the ways to build the cURL libraries that support Schannel and OpenSSL, respectively.

**2.1 Build the cURL libraries that use Schannel and zlib**

The Microsoft Secure Channel (Schannel) is a security package that facilitates the use of Secure Sockets Layer (SSL) and/or Transport Layer Security (TLS) encryption on Windows platforms. Schannel will use certificates from the Windows certificate store.  

Run the following  **nmake**  command to build the cURL libraries and the cURL binary that use Schannel and zlib.

```
nmake /f Makefile.vc mode=dll MACHINE=x64 WITH_ZLIB=dll ZLIB_PATH=C:\local\zlib
```

I ran the  **nmake** command with the following options.

Option

Description

mode=dll

Build a cURL dynamic library

MACHINE=x64

Target architecture (default is x86)

WITH_ZLIB=dll

Enable zlib support, DLL or static

ZLIB_PATH=C:\local\zlib

Custom path for zlib (C:\local\zlib)

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_nmake_schannel.png.transform/resize-768/q82/image.png)

cURL files are built in the  **.\builds\libcurl-vc-x64-release-dll-zlib-dll-ipv6-sspi-schannel** directory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_schannel_folder.png.transform/resize-768/q82/image.png)

The cURL and DLL files are in the  **bin**  directory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_schannel_bin.png.transform/resize-768/q82/image.png)

**2.2 Build the cURL libraries that use OpenSSL and zlib**  

cURL can be built to support OpenSSL. Run the following  **nmake**  command to build the cURL libraries and the cURL binary that use OpenSSL and zlib.  

```
nmake /f Makefile.vc mode=dll MACHINE=x64 WITH_SSL=dll SSL_PATH=C:\local\openssl1.1.1 WITH_ZLIB=dll ZLIB_PATH=C:\local\zlib
```

I ran the  **nmake** command with the following options.

Option

Description

mode=dll

Build a cURL dynamic library

MACHINE=x64

Target architecture (default is x86)

WITH_SSL=dll

Enable OpenSSL support, DLL or static

SSL_PATH=C:\local\openssl1.1.1

Custom path for OpenSSL (C:\local\openssl1.1.1)

WITH_ZLIB=dll

Enable zlib support, DLL or static

ZLIB_PATH=C:\local\zlib

Custom path for zlib (C:\local\zlib)

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_nmake_openssl.png.transform/resize-768/q82/image.png)

cURL files are built in the .\**builds\libcurl-vc-x64-release-dll-ssl-dll-zlib-dll-ipv6-sspi** directory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_openssl_folder.png.transform/resize-768/q82/image.png)

The cURL and DLL files are in the  **bin**  directory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_openssl_files.png.transform/resize-768/q82/image.png)

For other options, please refer to the  **README.md** file in the  **winbuild**  directory.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/curl_readme.png.transform/resize-768/q82/image.png)

At this point, the cURL binary and library files are built properly.

# Use the Libraries with Refinitiv Real-Time SDK C/C++

The OpenSSL, zlib, and cURL can be used with the Refinitiv Real-Time SDK C/C++ applications to connect to encrypted servers or Refinitiv Real-Time Optimized on the cloud. Refinitiv Real-Time SDK C/C++ on Windows uses libcurl that supports Schannel.

1. Copy the following files to the current directory of the Refinitiv Real-Time SDK C/C++ application.

-   C:\local\zlib\lib\zlib1.dll
-   C:\local\openssl1.1.1\bin\libcrypto-1_1-x64.dll
-   C:\local\openssl1.1.1\bin\libssl-1_1-x64.dll
-   C:\local\src\curl-7.83.1\builds\libcurl-vc-x64-release-dll-zlib-dll-ipv6-sspi-schannel\bin\libcurl.dll

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/consumer_dlls.png.transform/resize-768/q82/image.png)

2. Run the application. The application loads the OpenSSL, zlib, and cURL libraries found in the working directory and then connects to an encrypted server on Refinitiv Real-Time Optimized.

![](https://developers.refinitiv.com/content/dam/devportal/articles/how-to-build-openssl,-zlib,-and-curl-libraries-on-windows/consumer_run.png.transform/resize-768/q82/image.png)

# Summary

OpenSSL, zlib, and cURL are open-source and popular software projects used to secure communications over computer networks, compress data, and transfer data through various network protocols. Users can easily build the binary packages from the project’s source code. With this method, users can get the latest version of the packages. This article demonstrates step by step to build OpenSSL, zlib, and curl libraries from the source code on a Windows 10 machine. There are a few steps to building the package. The first step is downloading the source code package from the official project website. The second step is decompressing the package. The third step is configuring the package and the final step is building the package. The outcome contains executable files, development libraries, and header files.

# References

1. cURL. n.d. _cURL_. [online] Available at: <[https://curl.se/](https://curl.se/)> [Accessed 3 May 2022].

2. En.wikipedia.org. n.d. _cURL - Wikipedia_. [online] Available at: <[https://en.wikipedia.org/wiki/CURL](https://en.wikipedia.org/wiki/CURL)> [Accessed 3 May 2022].

3. OpenSSL. n.d. _OpenSSL_. [online] Available at: <[https://www.openssl.org/](https://www.openssl.org/)> [Accessed 3 May 2022].

4. En.wikipedia.org. n.d. _OpenSSL - Wikipedia_. [online] Available at: <[https://en.wikipedia.org/wiki/OpenSSL](https://en.wikipedia.org/wiki/OpenSSL)> [Accessed 3 May 2022].

5. Developers.refinitiv.com. n.d. _Refinitiv Real-Time C++ SDK | Refinitiv Developers_. [online] Available at: <[https://developers.refinitiv.com/en/api-catalog/refinitiv-real-time-opnsrc/rt-sdk-cc](https://developers.refinitiv.com/en/api-catalog/refinitiv-real-time-opnsrc/rt-sdk-cc)> [Accessed 3 May 2022].

6. En.wikipedia.org. n.d. _zlib - Wikipedia_. [online] Available at: <[https://en.wikipedia.org/wiki/Zlib](https://en.wikipedia.org/wiki/Zlib)> [Accessed 11 May 2022].

7. Zlib.net. n.d. _zlib Home Site_. [online] Available at: <[https://zlib.net/](https://zlib.net/)> [Accessed 11 May 2022].

8. Bacon, M., n.d. _What is Microsoft Schannel (Microsoft Secure Channel)? - Definition from WhatIs.com_. [online] TechTarget. Available at: <[https://www.techtarget.com/searchsecurity/definition/Microsoft-Schannel-Microsoft-Secure-Channel](https://www.techtarget.com/searchsecurity/definition/Microsoft-Schannel-Microsoft-Secure-Channel)> [Accessed 24 May 2022].

*Source: [https://developers.refinitiv.com/en/article-catalog/article/how-to-build-openssl--zlib--and-curl-libraries-on-windows](https://developers.refinitiv.com/en/article-catalog/article/how-to-build-openssl--zlib--and-curl-libraries-on-windows)*