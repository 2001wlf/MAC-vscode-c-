img=imread('lenazhouqizaosheng.jpg');%读取图片
[M,N]=size(img);%得到图像的高度和宽度
subplot(2,2,1);
imshow(img); %显示图像
title(''),xlabel('含有周期噪声的原图');

IF=fftshift(fft2(img));  %对加噪图像进行傅里叶变换，并将原点移至中心点
IFV=log(1+abs(IF));  %加噪图像的频谱
subplot(2,2,2);
imshow(IFV,[]); %显示加噪图像的频谱
title(''),xlabel('加噪图像的频谱');

freg=50;  %设置带阻滤波器的中心频率
width=5;  %设置带阻滤波器的频带宽度
ff=ones(M,N);
for i=1:M
    for j=1:N
        ff(i,j)=1-exp(-0.5*((((i-M/2)^2+(j-N/2)^2)-freg^2)/(sqrt((i-M/2)^2+(j-N/2)^2)*width))^2);%高斯带阻滤波器
    end
end
subplot(2,2,3);
imshow(ff,[]); %显示高斯带阻滤波器
title(''),xlabel('高斯带阻滤波器');

out=IF.*ff;    %矩阵点乘实现频域滤波
out=ifftshift(out);  %原点移回左上角
out=ifft2(out);  %傅里叶变换
out=abs(out);    %取绝对值
out=out/max(out(:));  %归一化
subplot(2,2,4);
imshow(out,[]); %显示滤波结果
title(''),xlabel('滤波效果图');
