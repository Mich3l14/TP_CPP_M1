#include "program.hpp"


void Program::execute(){
    cout << endl <<"[Input size: " << prog_input.size() <<"]" << endl;
    map<string, float> var_mem {};
    map<string, function<float(float)>> fun_mem {};

    //power of 2 function
    auto lambda = [](float i){return i*i;};
    fun_mem.emplace(pair{"pow2",lambda});

    Expression e{prog_input, var_mem, fun_mem};
    program = e.tokensFromString();
    for(auto line : program){
        vector<Token *> line_parsed = Expression::parse(get<0>(line));
        if(get<1>(line)){
            cout << "result: "<< Expression::eval(line_parsed) << endl;
        }
        for(auto& tk : line_parsed){
            delete tk;
        }
    }
}

string Program::executeString(){
    string output = "";
    map<string, float> var_mem {};
    map<string, function<float(float)>> fun_mem {};
    Expression e{prog_input, var_mem, fun_mem};
    program = e.tokensFromString();
    for(auto line : program){
        vector<Token *> line_parsed = Expression::parse(get<0>(line));
        if(get<1>(line)){
            output.append(to_string(Expression::eval(line_parsed)));
        }
        for(auto& tk : line_parsed){
            delete tk;
        }
    }
    return output;
}