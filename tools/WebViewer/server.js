const http = require('http')
const fs = require('fs')

const hostname = '127.0.0.1'
const port = 80

const server = http.createServer((req, res) => {

    var url = req.url
    if (url === '/') {
        res.writeHead(200, { 'Content-Type': 'text/html' })
        fs.readFile('./index.html','utf-8',function(err,data){
				if(err){
					throw err
				}
				res.end(data)
        });
    }
    else if (url === '/main.tga') {
        res.writeHead(200, { 'Content-Type': 'text/html' })
        fs.readFile('./main.tga',function(err,data){
				if(err){
					throw err
				}
				res.end(data)
        });
    }
        else if (url === '/tgaimage.min.js') {
        res.writeHead(200, { 'Content-Type': 'text/html' })
        fs.readFile('./tgaimage.min.js',function(err,data){
				if(err){
					throw err
				}
				res.end(data)
        });
    }
    else {
        res.writeHead(404, { 'Content-Type': 'text/html' })
        res.end()
    }
    
})

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`)
})
