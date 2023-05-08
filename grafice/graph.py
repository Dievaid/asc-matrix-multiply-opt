from matplotlib.pyplot import plot, show, xlabel, ylabel, ylim, legend
from numpy import array

xp = array([400, 600, 800, 1000, 1200])
yp_neopt = ([1.103738, 3.659254, 9.305335, 16.784485, 29.525051])
yp_opt = ([0.296790, 0.95665, 2.309975, 4.303251, 7.409517])
yp_blas = ([0.039316, 0.129759, 0.282245, 0.557283, 0.927857])

plot(xp, yp_opt)
xlabel("Test size")
ylabel("opt_m time")
ylim(0, 30)
show()

plot(xp, yp_neopt)
xlabel("Test size")
ylabel("neopt time")
ylim(0, 30)
show()

plot(xp, yp_blas)
xlabel("Test size")
ylabel("BLAS Time")
ylim(0, 30)
show()

plot(xp, yp_opt)
plot(xp, yp_neopt)
plot(xp, yp_blas)
legend(["opt_m", "neopt", "blas"])
xlabel("Test size")
ylabel("Time")
ylim(0,30)
show()
