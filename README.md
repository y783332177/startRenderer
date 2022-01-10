# startRenderer
- src
The source code
- Tools
    - WebViewer
    A light web tool write with nodejs, it can make u view the result image easily.
- shell
    - make.sh
    ``$ bash make.sh``  
    it will build the renderer and run it with cmake, and the application and the result image will be in the dir: build. I also copy the image to dir tools/WebViewer.
    - webViewer.sh
    ``$ bash make.sh``
    it will run webViwer and open the port 80, u can see the tga image through the web.
NOTE: u may need the env ``nodejs``, download it through yum or apt-get before u run webViwer~