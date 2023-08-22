
// import required module
const express = require('express');
const mqtt = require('mqtt');

const app = express();
const mqttClient = mqtt.connect('mqtt://192.168.0.19');

// MQTT topic to subscribe to
const mqttTopic = 'sensorReadings';

// if (mqttClient === mqtt.connect('mqtt://192.168.0.19')){
//   console.log('Using wifi');
// }else {
//   mqttClient === mqtt.connect('mqtt://192.168.43.110');

// }
// Set-up the Mqtt client to receive message
mqttClient.on('connect', () => {
    console.log('Connected to MQTT broker');
    mqttClient.subscribe(mqttTopic);
  });
  // This code subscribes to the Mqtt topic specified in the 'mqttTopic' the emits the 
  //recevied sensor value to the connected client via web sockets
  //
  mqttClient.on('message', (topic, message) => {
    if (topic === mqttTopic) {
      sensorData = JSON.parse(message.toString());
      console.log('Received sensor data:', sensorData);
  
      // Emit the sensor data to connected clients via WebSockets
      io.sockets.emit('sensorReadings', sensorData);
    }
  });
  // Setting up the Express web srver listening at port 3000
  const server = app.listen(3000, () => {
    console.log('Web server listening on port 3000');
  });
  
  // Enable WebSocket support
  const io = require('socket.io')(server);
  
  // Serve static files from the 'public' directory
  app.use(express.static('public'));
  
  // Start the WebSocket connection
  io.on('connection', (socket) => {
    console.log('New WebSocket connection');
  
    // Send the latest sensor data when a client connects
    socket.emit('sensorReadings', sensorData); 
  });
  


  
  