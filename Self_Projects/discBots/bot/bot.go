package bot

import (
	"encoding/csv"
	"fmt"
	"log"
	"os"
	"os/signal"
	"strconv"
	"strings"

	"github.com/bwmarrin/discordgo"
)

//Everything seems working. This code can be easily modified to intercat with different words, should try and send
// an embed for different things, i would wanna try and uploading a video from my computer when someone says
// hideo kojima, or hideo

var users = make(map[string]int)
var bannedWords = []string{"honkai", "hsr", "starrail"}

var BotToken string

const constFile string = "C:\\Users\\Horizon\\Documents\\Github\\Projs\\Self_Projects\\discBots\\users.csv"

// checks if there is something wrong with loading bot
func checkNilErr(e error) {
	if e != nil {
		log.Fatal("Error message")
	}
}

func readCsvFile(filePath string) (users map[string]int, err error) {
	f, err := os.Open(filePath)
	checkNilErr(err)
	defer f.Close()

	csvReader := csv.NewReader(f)
	lines, err := csvReader.ReadAll()
	if err != nil {
		log.Fatal("Unable to parse file as CSV for "+filePath, err)
	}

	users = make(map[string]int, len(lines))

	for i := range lines {
		users[lines[i][0]], err = strconv.Atoi(lines[i][1])
	}
	return users, nil
}

func mapToCsv(returnMap map[string]int) {
	f, err := os.OpenFile(constFile, os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0644)
	if err != nil {
		log.Fatal("Unable to read input file "+constFile, err)
	}
	defer f.Close()
	// delete the contents since we should have all the contects loaded in the program
	if err := os.Truncate(constFile, 0); err != nil {
		log.Printf("Failed to truncate: %v", err)
	}

	// load the contents into the files
	csvWriter := csv.NewWriter(f)
	if err != nil {
		log.Fatal("Unable to parse file as CSV for "+constFile, err)
	}

	for key, value := range returnMap {
		println(key, value)
		//s := make([]string, 0, len(key)+value)
		var s []string
		s = append(s, key)
		s = append(s, strconv.Itoa(value))
		fmt.Println(s)
		err := csvWriter.Write(s)
		if err != nil {
			log.Fatal("Unable to write to csv", err)
		}
	}
	csvWriter.Flush()

}

// checks the messages of users in order to add them to files and see if they are saying banned words
func checkMsg(discord *discordgo.Session, message *discordgo.MessageCreate) {
	// makes sure that the bot is somehow reading it self even though it shouldnt say banned words
	if message.Author.ID == discord.State.User.ID {
		return
	}
	fmt.Println(message.Author.GlobalName)

	// check if the messages contain a banned word
	for i := 0; i < len(bannedWords); i++ {
		if strings.Contains(message.Content, bannedWords[i]) {
			// warns the user than checks if they are in the lists of users
			discord.ChannelMessageSend(message.ChannelID, "You have been warned")
			curMem := message.Author.GlobalName
			users[curMem] += 1
		}
	}

}

/*
func warn(){

}

func punishment(){


}
*/

func Run() {

	// create a session
	discord, err := discordgo.New("Bot " + BotToken)
	checkNilErr(err)
	// add a event handler
	discord.AddHandler(checkMsg)

	// open session
	discord.Open()
	defer discord.Close() // close session, after function termination

	// keep bot running untill there is NO os interruption (ctrl + C)
	fmt.Println("Bot running....")
	c := make(chan os.Signal, 1)
	// load in users
	users, err = readCsvFile(constFile)
	fmt.Println(users)

	// interupt and end bot
	signal.Notify(c, os.Interrupt)
	// users["mura"] = 1
	<-c
	mapToCsv(users)

}
