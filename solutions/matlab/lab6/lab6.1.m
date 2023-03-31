img=imread('cameraman.tif');%读取图片
subplot(2,3,1);
imshow(img); %显示图像
title(''),xlabel('原图');


img_noise=double(imnoise(img,'gaussian',0.06)); %对图像附加高斯噪声
subplot(2,3,2);
imshow(img_noise,[]); %显示加噪图像
title(''),xlabel('高斯噪声污染的图像');

img_mean=imfilter(img_noise,fspecial('average',3));%对附加有高斯噪声的图像实行均值滤波器
subplot(2,3,3);
imshow(img_mean,[]);%显示算术均值滤波后的图像
title(''),xlabel('用3x3算数均值滤波器滤波');

img_mean=exp(imfilter(log(img_noise),fspecial('average',3)));%对附加有高斯噪声的图像实施几何均值滤波
subplot(2,3,4);
imshow(img_mean,[]);
title(''),xlabel('3x3的几何均值滤波器滤波');

Q=-1.5;  %对高斯噪声图像进行Q取负值的逆谐波滤波
img_mean=imfilter(img_noise.^(Q+1),fspecial('average',3))./imfilter(img_noise.^Q,fspecial(('average'),3));
subplot(2,3,5);
imshow(img_mean,[]);
title(''),xlabel('Q=-1.5的逆谐波滤波器滤波');

Q=1.5;  %对高斯噪声图像进行Q取正数的逆谐波滤波
img_mean=imfilter(img_noise.^(Q+1),fspecial('average',3))./imfilter(img_noise.^Q,fspecial(('average'),3));
subplot(2,3,6);
imshow(img_mean,[]);
title(''),xlabel('Q=1.5的逆谐波滤波器滤波');

