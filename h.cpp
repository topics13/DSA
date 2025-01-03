// step 1 extension install in vs-code
  // 1 C/C++ Microsoft
  // 2 C/C++ Compile Run danielpinto8zz6
  // 3 Code Runner Jun Han

// step 2 download and install MSYS2 from https://github.com/msys2/msys2-installer/releases/download/2024-01-13/msys2-x86_64-20240113.exe
 //terminal, install the MinGW-w64 toolchain by running the following command:
 //pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain


// step 3 
//Add the path of your MinGW-w64 bin folder to the Windows PATH environment variable by using the following steps:
 //In the Windows search bar, type Settings to open your Windows Settings.
 //Search for Edit environment variables for your account
 //In your User variables, select the Path variable and then select Edit.
 //Select New and add the MinGW-w64 destination folder you recorded during the installation process to the list. If you used the default settings above, then this will be the path: C:\msys64\ucrt64\bin.


// VS Code DOC
// https://code.visualstudio.com/docs/cpp/config-mingw
