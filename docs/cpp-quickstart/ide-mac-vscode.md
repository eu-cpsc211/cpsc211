# Using Visual Studio Code on Mac

These instructions demonstrate how to set up and use Visual Studio Code on Mac. The Clang compiler is used to compile C++ code.

**If you are using Windows, these are not the instructions you are looking for.**

## Install Clang

Check if Clang is installed on your Mac. To do this, open a terminal window and enter:

```
clang --version
```

If Clang is installed, you will see the version number that is installed.

![](./img/mac-vscode-clang.png)

If Clang is not installed, you will see a message indicating the command was not found. In that case, enter the following command in the terminal window:

```
xcode-select --install
```

Follow the instructions on screen to install the command line developer tools. This will install Clang.

## Install the Homebrew package manager

Go to https://brew.sh and follow the instructions to install the Homebrew package manager. You will have to copy a command and paste it into the Terminal app on your Mac.

Once completed, restart the Terminal app.

## Install CMake

In the Terminal app, execute the following command:

```
cmake --version
```

If CMake is installed correctly, this command will display the version of CMake you have installed. If you get an error that says something like "command not found", then you need to install CMake.

In the Terminal app, execute the following command:

```
brew install cmake
```

Follow the instructions provided. When complete, close the Terminal window and open a new one.

Execute the following command to verify CMake is installed correctly:

```
cmake --version
```

![](./img/mac-vscode-cmake-version.png)

## Install Visual Studio Code

Install [Visual Studio Code for Mac](https://code.visualstudio.com/docs/setup/mac). Make sure to copy the app into the Applications folder on your Mac.

## Open your project folder

Go back to the GitHub Desktop app. Click the **Open in Visual Studio Code** button to open your repository folder in VS Code. If you don't see that button, make sure the current repository is selected and the **Changes** tab is open.

![](./img/mac-vscode-open-in-vs.png)

Alternatively, you can open the folder directly in Visual Studio Code. In the top menu, select **File** -> **Open folder**.

![](./img/mac-vscode-open-folder.png)

Find the folder where you cloned your repository into and click **Open**.

![](./img/mac-vscode-open-folder-dialog.png)

Once the folder is open in VS Code, open the **Explorer** panel. You should see all the files from your repository in the Explorer panel. If you don't see any files, you've done something wrong.

![](./img/mac-vscode-explorer.png)

## Install extensions

Open the **Extensions** panel in VS Code. Install the following two extensions:

- C/C++ (search for `ms-vscode.cpptools`)
- CMake Tools (search for `ms-vscode.cmake-tools`)

The screenshot below shows where to search for extensions to install.

![](./img/mac-vscode-extension-cpp.png)

## Configure CMake

Open the **CMake Tools** panel. The icon looks like:

![](./img/mac-vscode-cmake-tools-icon.png)

In the **CMake Tools** panel, find the **Configure** section and click the button to **Select a Kit**.

![](./img/mac-vscode-cmake-tools-kit.png)

Select the Clang option from the list at the top of the window. If you don't see a Clang option, make sure Clang is installed (see instructions at the top of this document).

![](./img/mac-vscode-cmake-tools-kit-clang.png)

In the **CMake Tools** panel, find the **Build** section and click the button to change the build target.

![](./img/mac-vscode-cmake-tools-build.png)

Select the `hello-world` option from the list at the top of the window.

![](./img/mac-vscode-cmake-tools-build-select.png)

## Build and run

You are now ready to build and run the program. Open the `main.cpp` file from the **Explorer** panel. A text editor tab should open and show the file contents.

At the bottom of the VS Code window, click the **Build** button.

![](./img/mac-vscode-build.png)

If the build succeeds, you will see something like "Build finished with exit code 0" in the output window. If the build fails, switch to the **Problems** tab of the output panel and inspect any errors that are shown.

Once the build succeeds, you can run the program by clicking the play button at the bottom of the VS Code window.

![](./img/mac-vscode-run.png)

## Tip: Reconfigure CMake project

If you start having trouble building your project (or if things start acting strangely), you can try to delete all build files and rebuild the project from scratch.

![](./img/mac-vscode-delete-build.png)

Then go back to the **Configure CMake** section above and follow the instructions to reconfigure the CMake project.

## Continue quickstart guide

Continue the [C++ quickstart guide](./README.md).
