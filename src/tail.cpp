
int main() {
    
    uint8_t *img = new uint8_t[3*img_width*img_height];

    float wf = static_cast<float>(img_width);
    float hf = static_cast<float>(img_height);

    std::cout << "Resolution: " << img_width << "x" << img_height << "\n";

    for (int xp = 0; xp<img_width; xp++) {
        std::cout << std::fixed << std::setprecision(3) << '\r' << (100.0f*xp)/ (1.0f*img_width) << "%" << std::flush;
        // show fraction of lines done
        // std::cout << '\r' << xp << " / " << img_width << std::flush;
        for (int yp = 0; yp<img_height; yp++) {

            vec3 rayOrigin = vec3(0.0f,0.0f,-1.5f);
            float xf = static_cast<float>(xp);
            float yf = static_cast<float>(yp);
            vec2 uv = vec2((xf/wf-0.5f)*(wf/hf), yf/hf-0.5f);
            uv.y *= -1.0f;
            vec3 rayDirection = normalize(vec3(uv.x,uv.y,1.15f));

            //rayOrigin -= rayDirection*2.0;
            float t = intersect(rayOrigin, rayDirection, stepSize);
            if(t < 2.5) {
                vec3 p = (rayOrigin + rayDirection*t);
                //vec4 sp = projectionMatrix*viewMatrix*vec4(p,1.0);
                vec3 normal = calcNormal(p);
                vec3 c = shade(p, normal);
                //gl_FragColor = vec4(c, opacity);
                img[(xp+yp*img_width)*3+0] = min(c.r*255.0f,255.0f);
                img[(xp+yp*img_width)*3+1] = min(c.g*255.0f,255.0f);
                img[(xp+yp*img_width)*3+2] = min(c.b*255.0f,255.0f);
                
            } else {
                img[(xp+yp*img_width)*3+0] = 255;
                img[(xp+yp*img_width)*3+1] = 255;
                img[(xp+yp*img_width)*3+2] = 255;
            }
        }
    
    }

    save_image(img, img_width, img_height, "../output/test-render", 0);
    delete[] img;
    std::cout << "\n";
    return 0;
}
