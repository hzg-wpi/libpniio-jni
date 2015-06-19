#include <iostream>
#include <pni/io/nx/nx.hpp>
#include <pni/io/nx/algorithms/get_object.hpp>

#define cimg_display 0

#include "../CImg-1.6.4_pre060415/CImg.h"



using namespace std;
using namespace pni::io::nx;
using namespace pni::io::nx::h5;

int main(int argc,char **argv) {
    h5::nxfile f = h5::nxfile::open_file("/home/khokhria/Projects/hzg.wpn/jDataFormatServer/var/test.h5");

    h5::nxfield o = get_object(f.root(), nxpath::from_string("/entry/data/data"));

    std::cout << "field.name = " << o.name() << std::endl;
    std::cout << "field.size = " << o.size() << std::endl;

    cimg_library::CImg<int16_t> img(512,512);

    o(0,pni::core::slice(0,512),pni::core::slice(0,512)).read(262144,img.data());

    img.save_jpeg("test.out.jpeg");

    f.close();

    return 0;
}