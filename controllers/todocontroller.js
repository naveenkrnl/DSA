var bodyParser= require('body-parser')
var mongoose=require('mongoose');

//connect to the database
mongoose.connect("mongodb+srv://test:test@cluster-heyad.mongodb.net/test?retryWrites=true")

// Create a schema - this is like a blueprint
var todoSchema= new mongoose.Schema({
    item:String
});
var Todo = mongoose.model('todo',todoSchema);


var urlencodedParser = bodyParser.urlencoded({extended:false});
// var data=[{item:"get milk"},{item:"walk dog"},{item:"kick some coding ass"}];

module.exports =function(app){
 
    app.get('/todo',function(req,res){
        //get data from mongodb an pass it to view
        Todo.find({},function(err,data){
            if (err) throw err;
            res.render('todo',{todos:data});
        });
    });

    app.post('/todo',urlencodedParser,
    function(req,res){
        // get data from view and add it to mongoab
        var newTodo=Todo(req.body).save(function(err,data){
            if (err) throw err;
            res.json(data);
        });
    });

    app.delete('/todo/:item',function(req,res){
        //delete the requested item from mongodb
        Todo.find({item: req.params.item.replace(/\-/g," ")}).remove(function(err,data){
            if (err) throw err;
            res.json(data);
        });
    });
};