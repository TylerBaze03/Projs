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

var dotw string[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
var BotToken string
var constFile string = "C:\Users\Horizon\Documents\Github\Projs\Self_Projects\ScheduleBot\schedule.csv"

// Formatted in the following way:
// If the key is a day of the week or multiple days, it is a weekly 
// If the Key is a date in format MM/DD/YYYY than it is a day
// This is relavenmt for different removing and adding dates to the schedule 
var realSchedule map[string]string


func checkNilErr(e error) {
	if e != nil {
		log.Fatal("Error message")
	}
}

func readCsvFile(filePath string) (sched map[string]string, err error) {
	f, err := os.Open(filePath)
	checkNilErr(err)
	defer f.Close()

	csvReader := csv.NewReader(f)
	lines, err := csvReader.ReadAll()
	if err != nil {
		log.Fatal("Unable to parse file as CSV for "+filePath, err)
	}

	sched = make(map[string]string, len(lines))

	for i := range lines {
		sched[lines[i][0]], err = lines[i][1]
	}
	return sched, nil
}

func mapToCsv(returnMap map[string]string) {
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
		s = append(s, value)
		fmt.Println(s)
		err := csvWriter.Write(s)
		if err != nil {
			log.Fatal("Unable to write to csv", err)
		}
	}
	csvWriter.Flush()

}

// checks the messages of users in order to detect commands
func checkMsg(discord *discordgo.Session, message *discordgo.MessageCreate) {
	// makes sure that the bot is somehow reading it self 
	if message.Author.ID == discord.State.User.ID {
		return
	}
	fmt.Println(message.Author.GlobalName)

	switch {
	case strings.Contains(message.Content, "!help"):
		helpMsg(message)
	case strings.Contains(message.Content, "!add"):
		addCmd()
	case strings.Contains(message.Content, "!remove"):
		removeCmd()
	case strings.Contains(message.Content, "!weekly"):
		weeklySched()
	case strings.Contains(message.Content, "!search"):
		searchDate()
	case strings.Contains(message.Content, "!replace"):
		replaceDate()
	case strings.Contains(message.Content, "!upcoming"):
		upcoming()
	 // add more cases if required
	}

	/*
	for i := 0; i < len(bannedWords); i++ {
		if strings.Contains(message.Content, bannedWords[i]) {
			// warns the user than checks if they are in the lists of users
			discord.ChannelMessageSend(message.ChannelID, "You have been warned")
			curMem := message.Author.GlobalName
			users[curMem] += 1
		}
	}
	*/

}
func helpMsg(message *discordgo.MessageCreate){
	discord.ChannelMessageSend(message.ChannelID, "Commands:\n!add <Date> <Hours>\n\tThis is used in order to add a single date to the schedule\n!remove <Date or days>\n\tThis is used in order to remove a single day or an entire weekly schedule\n!weekly <Days> <Hours>\n\t Adds a weekly schedule to the scheduler with designated hours and will @ people when it is the day\n!search <Date or day>\n\t Checks if a certain date or day is already being used\n!upcoming\n\t Sends the current schedule and dates upcoming\nAll Singular dates must be in format MM/DD/YYYY")
}
func addCmd(key string, value string,message *discordgo.MessageCreate )string{
	if realSchedule[key] != value{
		return discord.ChannelMessageSend(message.ChannelID, "Date is already taken, please choose another or use !replace <Date or day> to replace it"
	}
	else{
		realSchedule[key] = value
		discord.ChannelMessageSend(message.ChannelID, key, "at", value, "added to schedule")
	}
}
func removeCmd(key string,message *discordgo.MessageCreate){

}
func weeklySched(key string, value string,message *discordgo.MessageCreate ){

}
func upcoming(){

}
func searchDate(key string,message *discordgo.MessageCreate){

}
func replaceDate(key string, value string, message *discordgo.MessageCreate){

}

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
