class Solution {
public:
    string simplifyPath(string path) {
        regex sls("/{2,}");
        path = regex_replace(path, sls, "/");

        stringstream ss(path);
        stack<string> parts;
        string part;
        while(getline(ss, part, '/')){
            if(part.empty()) continue;
            else if (part == "..") {
                if (!parts.empty()) parts.pop();
            }
            else if (part != "."){
                parts.push(part);
            }
        }
        string output;
        for(; !parts.empty(); parts.pop()){
            output = "/" + parts.top().append(output);
        }
        if (output.empty()) return "/";
        return output;
    }
};
