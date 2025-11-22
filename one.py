import qrcode as qr
img1=qr.make("janyamr2005@gmail.com")
img2=qr.make("8183892301")
img1.save("email_qrimage.png")
img2.save("phn_qrimage.png")