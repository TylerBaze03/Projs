package main

import (
	"fmt"      // formatting and printing values to the console.
	"log"      // logging messages to the console.
	"net/http" // Used for build HTTP servers and clients.
)

// Port we listen on.
const portNum string = ":8888"

// Handler functions.
func Home(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "C:\\Users\\Horizon\\Documents\\proj\bllaiza.me\bllaizame.html")
}

func Info(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Info page")
}

func main() {
	log.Println("Starting our simple http server.")

	// Registering our handler functions, and creating paths.
	http.HandleFunc("/", Home)
	http.HandleFunc("/info", Info)

	log.Println("Started on port", portNum)
	fmt.Println("To close connection CTRL+C :-)")

	// Spinning up the server.
	err := http.ListenAndServe(portNum, nil)
	if err != nil {
		log.Fatal(err)
	}
}
