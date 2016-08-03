var snakeApp = angular.module("snakeWebClient", ['ngWebSocket']);
snakeApp.controller("snakeWebClientController", function ($scope,$websocket) {
    var result;
    ws = $websocket("ws://127.0.0.1:1080");
    ws.onOpen(function () {
        ws.send("work ok");
    });
    ws.onMessage(function (evt) {
        if (evt.data == "STOP") { }
        else { 
       dataJson = JSON.parse(evt.data);
        $scope.result = dataJson.table.width;
        angular.element(document.getElementById("Table")).css("height", dataJson.table.height * 10).css("width", dataJson.table.width * 10).css("background-color", "lightgray");
        angular.element(document.getElementById("Food")).css("left", dataJson.snakefood.x * 10).css("top", dataJson.snakefood.y * 10);
        angular.element(document.getElementById("Head")).css("left", dataJson.snakebody[0].point0.x * 10).css("top", dataJson.snakebody[0].point0.y * 10);
        }


        ws.send("work ok");
    });
    
});

