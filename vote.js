function vote()
{
    var name=document.getElementById("Name").value;
    var age=document.getElementById("age").value;
    var res=document.getElementById("result");
    if(age>=18)
    {
        res.innerHTML=name+" you are eligible to vote";
    }else{
        res.innerHTML=name+" you are not eligible to vote";
    }
}