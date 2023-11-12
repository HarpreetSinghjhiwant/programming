import express, { urlencoded } from "express";
import { dirname } from 'path';
import { fileURLToPath } from 'url';

const __dirname = dirname(fileURLToPath(import.meta.url));

const app = express()
app.use(express.urlencoded({extended:true}))
app.use(express.static("public"));
app.set("view engine","ejs");

app.get("/",(req,res)=>{
    res.render(__dirname+"/index.ejs",{data:1});
})

app.post("/",(req,res)=>{
    var data = parseInt(req.body.first) + parseInt(req.body.second);
    res.render(__dirname+"/index.ejs",{data:data});
})

app.listen(3000,()=>{
    console.log("Server started");
})