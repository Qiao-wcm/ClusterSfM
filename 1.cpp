/**
 *  输入 ： 全局重建sfm的image.txt camera.txt points.txt 
 *          每个小组的image_id
 *  输出 ： 不同小组的image_id对应的 image.txt camera.txt points.txt
 *  算法 ： 1 从txt中读取每个小组的image_id，并存入vector中
 *          2 根据vector中的image_id来拉取camera对应的三维坐标images.txt 
 * */


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// 读取txt行函数
vector<string> ReadText(string filename, int line, int num )
{
    ifstream fin;
    fin.open(filename, ios::in);
    vector<string> cameras;
    string strVec[num+1];
    int i = 0;

    while (!fin.eof())
    {
        string inbuf;
        getline(fin, inbuf, '\n');
        strVec[i] = inbuf;
        i = i + 1;
    }

    cameras.emplace_back(strVec[line]);
    cameras.emplace_back(strVec[line + 1]);

    return cameras;

    // return strVec[line - 1];   
}

int main(){

    // 从txt中读取camera_id存入vector
    std::vector<int> cameras_id;
    
    std::ifstream cameras("/data6/wcm/data/Pro2Out0930/NCut/12/cluster_id/c0.txt");
    string c;

    while (getline(cameras, c))
    {
        std::stringstream cameras(c);
        string tmp;

        while (getline(cameras, tmp))
        {
            cameras_id.push_back(std::stoi(tmp));
        }
        
    }

    std::cout << "cameras num = " << cameras_id.size() << std::endl;

    std::ofstream cluster_cameras("/data6/wcm/data/Pro2Out0930/NCut/12/cluster_cameras/c0/images.txt");
    vector<string> filename0;
    // string filename0;
    // string filename1;

    for (size_t i = 0; i < cameras_id.size(); i++)
    {
        filename0 = ReadText("/data6/wcm/data/Pro2Out0930/sfm/images.txt", (cameras_id[i] - 1 ) * 2 , 200000);
        // cluster_cameras.close();

        // filename1 = ReadText("/data6/wcm/data/Building/sfm/images.txt", cameras_id[i+1] - 1, 258);
        // cluster_cameras << filename0 <<  std::endl;
        // cluster_cameras << filename1 << std::endl;
        for (auto const f : filename0 )
        {
            cluster_cameras << f << std::endl;
        }
        
    }

    return 0;

}


