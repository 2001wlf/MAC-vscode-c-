img=imread('cameraman.tif');%读取图片
subplot(2,3,1);
imshow(img); %显示图像
title(''),xlabel('原图');

img_noise=double(imnoise(img,'salt & pepper',0.06));%加“椒盐”噪声
subplot(2,3,2);
imshow(img_noise,[]); %显示图像
title(''),xlabel('椒盐噪声污染的图像');

img_mean=imfilter(img_noise,fspecial('average',5));%对附加“椒盐”噪声的图像实行算术均值滤波
subplot(2,3,3);
imshow(img_mean,[]); %显示图像
title(''),xlabel('均值滤波结果');

img_median=medfilt2(img_noise);%对附加“椒盐”噪声的图像实行中值滤波
subplot(2,3,4);
imshow(img_median,[]); %显示图像
title(''),xlabel('中值滤波结果');

img_median2=medfilt2(img_noise);
subplot(2,3,5);
imshow(img_median2,[]); %显示图像
title(''),xlabel('再次中值滤波结果');

