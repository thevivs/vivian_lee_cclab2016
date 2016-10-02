$(document).ready(function() {
  init();
});

var init = function() {

  console.log("gif?");

  $('#buttonOne').click(function(e) {
    e.preventDefault();
    getGifOne($('#boxOne').val());
    console.log($('#boxOne').val());
  });


  $('#buttonTwo').click(function(e) {
    e.preventDefault();
    getGifTwo($('#boxTwo').val());
    console.log($('#boxTwo').val());
  });

  $('#buttonThree').click(function(e) {
    e.preventDefault();
    getGifThree($('#boxThree').val());
    console.log($('#boxThree').val());
  });

  $('#buttonFour').click(function(e) {
    e.preventDefault();
    getGifFour($('#boxFour').val());
    console.log($('#boxFour').val());
  });


};


function getGifOne(query) {
  // console.log(query);
  var giphyUrl = "http://api.giphy.com/v1/gifs/search?q=" + query + "&api_key=dc6zaTOxFJmzC";
  console.log(giphyUrl);
  $.ajax({
    url: giphyUrl,
    data: {
      q: query,
      limit: 1
    },

    success: function(response) {
      // console.log(response);
      console.log(response.data[0].images.downsized.url);
      testSource = response.data[0].images.downsized.url;
      loadGifOne(testSource);
      // console.log(testSource);
    }
  });
};


function getGifTwo(query) {
  // console.log(query);
  var giphyUrl = "http://api.giphy.com/v1/gifs/search?q=" + query + "&api_key=dc6zaTOxFJmzC";
  console.log(giphyUrl);
  $.ajax({
    url: giphyUrl,
    data: {
      q: query,
      limit: 1
    },

    success: function(response) {
      // console.log(response);
      console.log(response.data[0].images.downsized.url);
      testSource2 = response.data[0].images.downsized.url;
      loadGifTwo(testSource2);
      // console.log(testSource);
    }
  });
};

function getGifThree(query) {
  // console.log(query);
  var giphyUrl = "http://api.giphy.com/v1/gifs/search?q=" + query + "&api_key=dc6zaTOxFJmzC";
  console.log(giphyUrl);
  $.ajax({
    url: giphyUrl,
    data: {
      q: query,
      limit: 1
    },

    success: function(response) {
      // console.log(response);
      console.log(response.data[0].images.downsized.url);
      testSource3 = response.data[0].images.downsized.url;
      loadGifThree(testSource3);
      // console.log(testSource);
    }
  });
};

function getGifFour(query) {
  // console.log(query);
  var giphyUrl = "http://api.giphy.com/v1/gifs/search?q=" + query + "&api_key=dc6zaTOxFJmzC";
  console.log(giphyUrl);
  $.ajax({
    url: giphyUrl,
    data: {
      q: query,
      limit: 1
    },

    success: function(response) {
      // console.log(response);
      console.log(response.data[0].images.downsized.url);
      testSource4 = response.data[0].images.downsized.url;
      loadGifFour(testSource4);
      // console.log(testSource);
    }
  });
};


function loadGifOne(url) {
  // console.log(url);
  $('#panelOne').append('<img src="' + url + '">');
}


function loadGifTwo(url) {
  // console.log(url);
  $('#panelTwo').append('<img src="' + url + '">');
}

function loadGifThree(url) {
  // console.log(url);
  $('#panelThree').append('<img src="' + url + '">');
}

function loadGifFour(url) {
  // console.log(url);
  $('#panelFour').append('<img src="' + url + '">');
}


//giphy.gif
