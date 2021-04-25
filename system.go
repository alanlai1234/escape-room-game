//TODO: able to read messages in the inventory

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var pocket map[string]int

// for use of listing possible actions
type options struct {
	v string // verb
	n string // noun
}

func search(nums []int, target int) bool {
	for _, k := range nums {
		if k == target {
			return true	
		}
	}
	return false
}

func in(a []options) int {
START:
	read := bufio.NewReader(os.Stdin)
	fmt.Print(">>")
	input, _ := read.ReadString('\n')
	input = strings.TrimSpace(input)
	if input == "pocket" {
		fmt.Println("inventory:")
		for key, val := range pocket {
			fmt.Println(val, key)
		}
		goto START
	} else if input == "help" {
		// TODO
		fmt.Println("help page:")
		goto START
	} else if input == "exit" {
		fmt.Println("game over")
		return 100
	}
	return parse(input, a)
}

/* return the position in the options array
if there is no verb or noun, pass a empty string*/
func parse(split string, actions []options) int {
	//split = strings.TrimSpace(split)
	save := strings.Split(split, " ")
	var find []int
	var ans int
	vflag := false
	nflag := false
	var check bool
	var vv string

	for _, i := range save {
		// verb
		if !vflag {
			vv, check = vdict[i]
			if check {
				for a, k := range actions {
					if k.v == vv {
						if !nflag {
							find = append(find, a)
							vflag = true
						}else if search(find, a) {
							vflag = true
							ans = a
							break
						}
						//if res == -1 {
							//res = a // temporarily set to founded verb position
							//vflag = true
						//} else if a == res {
							//vflag = true
						//}
					}
				}
				continue
			}
		}

		// noun
		if !nflag {
			vv, check = ndict[i]
			if check {
				for a, k := range actions {
					if k.n == vv {
						if !vflag {
							nflag = true
							find = append(find, a)
						} else if search(find, a){
							nflag = true
							ans = a
							break
						}
						//if res == -1 {
							//res = a
							//nflag = true
						//} else if a == res {
							//nflag = true
						//}
						//TODO: if founded noun isn't the same position as the verb
						break
					}
				}
				continue
			}
		}

	}

	if len(find) == 0 {
		return -1
	}
	//if actions[ans].v != "-1" && !vflag {
		//return -1
	//}
	//if actions[res].n != "-1" && !nflag {
		//return -1
	//}
	if !vflag || !nflag{
		return -1
	}

	return ans
}

