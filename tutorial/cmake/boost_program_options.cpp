#include <iostream>
#include <string>

#include <boost/program_options.hpp>

namespace po = boost::program_options;
int main(int argc, char* args[]){
    po::options_description description("allowed options");
    description.add_options()
        ("cascade,c", po::value<std::string>(),"cascade_model_file")
        ("video,v", po::value<std::string>(), "video_file");
    po::variables_map variables_map;
    po::store(po::parse_command_line(argc, args, description), variables_map);
    po::notify(variables_map);

    std::cout<<variables_map["video"].as<std::string>()<<std::endl;
    return 0;

}
