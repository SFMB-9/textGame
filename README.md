# textGame

My own fancy terminal game.

(trying) to use the most recent Object Oriented Programming standards.

## About this program
<div style="text-align: justify">
The most relevant aspect of this implementation is the use of the Nlohmann/json library (via 'json.hpp') to solve lots of problems creatively: for instance, specifications for styling a box printed in the terminal are sent via a json object which includes things like 'padding' or 'color'.
</div>

## Required Software

[Python](https://www.python.org/) and C++ are required to use this software.

I recommend using [Visual Studio Code](https://code.visualstudio.com/) for straightforward access to the source code, however you may use the IDE of your choice.

**Windows:**

Make sure to downlaod the [.NET core SDK](https://dotnet.microsoft.com/en-us/download) (either .NET versions 6.0 or 7.0). Alternatively, you may download the latest version of [Visual Studio Community](https://visualstudio.microsoft.com/downloads/) and install the SDK by following the installation process.

**MacOS:**

Make sure to have the latest version of [Xcode](https://developer.apple.com/xcode/) installed.

Also, make sure to download the latest version of [Visual Studio Community](https://visualstudio.microsoft.com/downloads/) in order to set up the .NET core SDK via the installation process, as well as a [mono stable release](https://www.mono-project.com/download/stable/) from the [Mono](https://www.mono-project.com/) website.

## Running the software
For the textGame, setup your terminal to the `/src` directory. Input `main.cpp`.