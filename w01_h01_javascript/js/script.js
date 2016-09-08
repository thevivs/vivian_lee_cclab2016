// var mouseClick = true;

// var listDiv = document.getElementById("list_container");



//STILL WANT THIS DO NOT DELETE
// document.addEventListener("click", function()){
// 	getElementById("header_container"). 
// 	console.log("clicked");

// 	var listDiv = document.getElementById("list_container");

// 	listDiv.style.opacity = 0;

// 		clickFunction(function(){


// 			listDiv.style.opacity = 1;

// 		}, 0);

// }


// var headerContainer = document.getElementsByID("header_container");
// var listContainer = document.getElementsByClassName("list_container");

// document.getElementById("headerContainer").onclick = function (){
// 	var listContainer = document.getElementById("container");
// 		listContainer.style.opacity = 1;

// 	console.log ("pressed");
// }



//the idea is that when you first start off, the list will be transparent.
//After you click on groceries, the list will appear
//and then they start to animate


var eggs = document.getElementById("eggs");
var milk = document.getElementById("milk");
var bread = document.getElementById("bread");
var apples = document.getElementById("apples");
var pasta = document.getElementById("pasta");
var broccoli = document.getElementById("broccoli");
var listArray = document.getElementById("container");


var array = [eggs, milk, bread, apples, pasta, broccoli];


document.addEventListener("DOMContentLoaded", function() {
    // var seconds = 0;
    // var temp;

    // listArray.style.opacity = 0;

    for (var i = 0; i < array.length; i++) {
        array[i].style.opacity = 0;
    }

    // 	eggs.style.opacity = 0;
    // 	milk.style.opacity = 0;
    // 	bread.style.opacity = 0;
    // 	apples.style.opacity = 0;
    // 	pasta.style.opacity = 0;
    // 	broccoli.style.opacity = 0;

});


function showGroceries() { //here is the function we want to call

    console.log("show groceries running");

    // listArray.style.opacity = 1;


    // array.style.opacity = 1;


    for (var i = 0; i < array.length; i++) {
        array[i].style.opacity = 1;
    };

}

// eggs.style.opacity = 1;
// milk.style.opacity = 1;
// bread.style.opacity = 1;
// apples.style.opacity = 1;
// pasta.style.opacity = 1;
// broccoli.style.opacity = 1;


function disappear(element) { //here is the function we want to call

	element.style.opacity = 0.1;
    // console.log("show groceries running");


}



