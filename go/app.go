package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"

	"github.com/alecthomas/kong"
	kongyaml "github.com/alecthomas/kong-yaml"
)

var config struct {
	Port int `required:"" default:"8080" env:"LPG_PORT"`
}

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
	kong.Parse(&config, kong.Configuration(kongyaml.Loader, "./config.yaml"))

    http.HandleFunc("GET  /hello", helloHandler)
	http.HandleFunc("POST /ping",  pingHandler)
	
    log.Fatal(http.ListenAndServe(fmt.Sprint(":",config.Port), nil))
}
