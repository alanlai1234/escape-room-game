package main

import (
	"fmt"
	"strconv"
	"github.com/eiannone/keyboard"
)

func main() {
	// init
	next := "(press enter to continue)"
	err_msg := "don't understand your command"
	pocket = make(map[string]int)

	//welcome
	fmt.Println("welcome to escape room\n" + next) 
	keyboard.GetSingleKey() 
	//fmt.Println("read and enter text to progress through the game\n" + next)
	//keyboard.GetSingleKey()
	//fmt.Println("remember to only use present simple tense(no wied grammar) with 2 to 3 words\n" + next)
	//keyboard.GetSingleKey()
	//fmt.Println("type [pocket] to view what you have taken in the game.\n" + next)
	//keyboard.GetSingleKey()
	//fmt.Println("good luck with your adventure!\n" + next)
	//keyboard.GetSingleKey()

	//start
	fmt.Println("\n---------------------------------")

	fmt.Println("You are in a room with a shelf and a table with few things on it.")
A:
	switch in([]options{{"look", "table"}, {"open", "shelf"}, {"look", "paper"}, {"choose", "pen"}, {"choose", "key"}, {"go", "left"}, {"look", "note"}}) {
	case 0:
		fmt.Println("There is a pen and a note paper with words on it.")
		goto A
	case 1:
		fmt.Println("there's a pile of papers in it, and a key on top of them.")
		goto A
	case 2,6:
		fmt.Println("message:\nI'll be back in just a minute, just to get some papers printed. And the bathroom is in the west side of the room.\n(a paper added to your inventory)")
		pocket["note message"] = 1
		goto A
	case 3:
		fmt.Println("(a pen added to your inventory)")
		pocket["pen"] = 1
		goto A
	case 4:
		fmt.Println("(a key added to your inventory)")
		pocket["key"] = 1
		goto A
	case 5:
		break
	case 100:
		return 
	default:
		fmt.Println(err_msg)
		goto A
	}
	fmt.Println("a door is in front of you")
B:
	switch in([]options{{"open", "door"}, {"use", "key"}, {"go", "left"}, {"go", "right"}}) {
	case 0:
		fmt.Println("the door is locked, use a key to open.")
		goto B
	case 1:
		fmt.Println("shoot.. the key has been eroded, it's broken! Hold up, there's something at the left, might want to move closer to see it clearly.")
		goto B
	case 2:
		break
	case 3:
		fmt.Println("You are in a room with a shelf and a table with few things on it.")
		goto A
	case 100:
		return
	default:
		fmt.Println(err_msg)
		goto B
	}

	fmt.Println("there is a big bulleton board in front of you, might find some helpful informations.")
C:
	switch in([]options{{"look", "board"}}) {
	case 0:
		fmt.Println("Oh no, there's too many notes on the bulliton board at the same time, gotta do it in a smart way..")
		if notegame() {
			break
		}else {
			fmt.Println("you failed, try it again.")
			goto C
		}
		
	case 100:
		return
	default:
		fmt.Println(err_msg)
		goto C
	}
}

func notegame() bool{
	var in string
	fmt.Println("1+1=?")
	fmt.Scanln(&in)
	if()
	return true
}
