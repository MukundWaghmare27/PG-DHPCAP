
package main

import "fmt"

// Function to reverse a string
func reverseString(s string) string {
	reversed := ""
	// Loop through each character of the string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		reversed += string(s[i])
	}
	return reversed
}

func main() {
	var inputStrings [10]string

	// Accept 10 strings from the user
	fmt.Println("Please enter 10 strings:")

	for i := 0; i < 10; i++ {
		fmt.Printf("Enter string %d: ", i+1)
		fmt.Scanln(&inputStrings[i])
	}

	// Display each string in reverse order
	fmt.Println("\nStrings in reverse order:")
	for _, str := range inputStrings {
		fmt.Println(reverseString(str))
	}
}




