#main.py for http server 
import socket
from http import HTTPStatus

class TCP_pro:
    def __init__(self, host = socket.gethostname(), port = 8888):
        self.host = host
        self.port = port
    def start(self):
        #socket object
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        #binding the docking object to the adress and port we wanted
        s.bind((self.host, self.port))
        #get connections for 5 seconds
        s.listen(5)

        print("Listening at ",s.getsockname())

        while True:
            conn, addr = s.accept()

            print('Connected by', addr)

            #read the data sent by client
            # only read 1024 bytes
            data = conn.recv(1024)

            #using new function to handle the request
            response = self.handle_request(data)

            #send back to client
            conn.sendall(response)

            #close connection
            conn.close()
    def handle_request(self, data):

        return data
    
class HTTPServer(TCP_pro):
    headers = {
            'Server': 'crude server',
            'Content-Type' : 'text/html',
        }
    status_codes = {
        200: 'OK',
        404: 'Not Found',
    }
    def handle_request(self, data):

        response_line = self.response_line(HTTPStatus.OK)

        response_headers = self.response_headers()

        blank_line= b'\r\n'

        response_body=  b"""
            <html>
                <body>
                    <h1>Request received!</h1>
                <body>
            </html>
        """

        return b''.join([response_line, response_headers, blank_line, response_body]) # send bytes, not string
    
    def response_line(self, status_code):
        #gen response line
        #get the needed response code inputed into function
        reason= self.status_codes[status_code]

        #actually creating the line
        line = "HTTP/1.1 %s %s \r\n" % (status_code, reason)

        #return the reponse line encoded into bytes
        return line.encode()

    def response_headers(self, extra_headers = None):
        #extra_headers can be dictionary for senfin headers into the current response

        headers_copy = self.headers.copy() #create copy of headers inside of the function
        if extra_headers:
            headers_copy.update(extra_headers)

        headers = ""
        for h in headers_copy:
            headers+= "%s: %s \r\n" % (h, headers_copy[h])

        return headers.encode() #same reason to encode as before



if __name__ == '__main__':
    server = HTTPServer()
    server.start()