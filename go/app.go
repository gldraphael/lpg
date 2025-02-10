package main

import (
	"encoding/json"
	"log"
	"net/http"
)

type Message struct 
{
	Msg string `json:"msg"`
}

func helloHandler(w http.ResponseWriter, r *http.Request) {
    w.Header().Set("Content-Type", "application/json")
	response := Message{Msg: "Hello, world!"}
	json.NewEncoder(w).Encode(response)
}

func pingHandler(w http.ResponseWriter, r *http.Request) {
    w.Header().Set("Content-Type", "application/json")
	response := Message{Msg: "pong"}
	json.NewEncoder(w).Encode(response)
}

func main() {
    http.HandleFunc("GET /hello", helloHandler)
	http.HandleFunc("POST /ping", pingHandler)
    log.Fatal(http.ListenAndServe(":8080", nil))
}
