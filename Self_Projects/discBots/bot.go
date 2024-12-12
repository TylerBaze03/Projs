package main

import (
    "fmt"
    "log"
    "os"
    "os/signal"
    "strings"
    "hash/maphash"
    "github.com/bwmarrin/discordgo"
    "encoding/csv"
)

//todo: finish importing a csv to a map and map to a csv in order to maintain the bot even when not active
// this may have to utilize the warn and punishment system but would rather use punishment for when the number is above 3 
// than check status in order to exhert warnings



var botToken string
var users = make(map[string]int)
var bannedWords = []string{"honkai", "hsr", "honkai starrail"}


//checks if there is something wrong with loading bot
func checkNilErr(e error) {
    if e != nil {
        log.Fatal("Error message")
    }
}

// reading in a csv of all the users and their history
func readCsvFile(filePath string) [][]string {
    f, err := os.Open(filePath)
    if err != nil {
        log.Fatal("Unable to read input file " + filePath, err)
    }
    defer f.Close()

    csvReader := csv.NewReader(f)
    records, err := csvReader.ReadAll()
    if err != nil {
        log.Fatal("Unable to parse file as CSV for " + filePath, err)
    }

    return records
}

func csvToMap(returnMap []map[string]int){


}
func mapToCsv(returnMap []map[string]int){


}

func checkStatus(){


}


// checks the messages of users in order to add them to files and see if they are saying banned words
func checkMsg(discord *discordgo.Session, message *discordgo.MessageCreate, i *discordgo.Interaction) *discordgo.User{
    // makes sure that the bot is somehow reading it self even though it shouldnt say banned words
    if message.Author.ID == discord.State.User.ID {
        return
    }
    // check if the messages contain a banned word
    if strings.Contains(message.Content, bannedWords) == true{
        // makes sure this is a user
        if i.Member != nil {
            // warns the user than checks if they are in the lists of users 
            discord.ChannelMessageSend(message.ChannelID, "You have been warned")
            if i.Member.Contains(users) == true {
                users[i.Member] += 1
            }
            else{
                users[i.Member] = 1
            }
        }
    }

}

func warn(){
    
}

func punishment(){


}

func run(){

    // create a session
    discord, err := discordgo.New("Bot " + BotToken)
    checkNilErr(err)

    // add a event handler
    discord.AddHandler(newMessage)

    // open session
    discord.Open()
    defer discord.Close() // close session, after function termination

    // keep bot running untill there is NO os interruption (ctrl + C)
    fmt.Println("Bot running....")
    c := make(chan os.Signal, 1)
    signal.Notify(c, os.Interrupt)
    <-c


}