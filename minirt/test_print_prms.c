void		print_prms(t_prms *prms)
{
	t_list	*tmp;

	printf("Res: %d, %d\n", prms->res.x, prms->res.y);
	printf("Amb: r:g:b %d:%d:%d power %.2f\n", prms->amb.rgb.r, prms->amb.rgb.g, prms->amb.rgb.b, prms->amb.power);
	tmp = prms->cameras;
	while (prms->cameras)
	{
		printf("Cam: pos %.2f:%.2f:%.2f norm %.2f:%.2f:%.2f fov %.2f\n",
		((t_cam*)(prms->cameras->content))->pos.x,
		((t_cam*)(prms->cameras->content))->pos.y, 
		((t_cam*)(prms->cameras->content))->pos.z,
		((t_cam*)(prms->cameras->content))->norm.x,
		((t_cam*)(prms->cameras->content))->norm.y, 
		((t_cam*)(prms->cameras->content))->norm.z,
		((t_cam*)(prms->cameras->content))->fov);
		prms->cameras = prms->cameras->next;
	}
	prms->cameras = tmp;
	tmp = prms->lights;
	while (prms->lights)
	{
		printf("Light: pos %.2f:%.2f:%.2f ratio: %.2f rgb %d:%d:%d\n",
		((t_light*)(prms->lights->content))->pos.x,
		((t_light*)(prms->lights->content))->pos.y, 
		((t_light*)(prms->lights->content))->pos.z,
		((t_light*)(prms->lights->content))->ratio,
		((t_light*)(prms->lights->content))->rgb.r,
		((t_light*)(prms->lights->content))->rgb.g, 
		((t_light*)(prms->lights->content))->rgb.b);
		prms->lights = prms->lights->next;
	}
	prms->lights = tmp;
	tmp = prms->figures;
	while (prms->figures)
	{
		printf("%s: xyz1 %.2f:%.2f:%.2f xyz2 %.2f:%.2f:%.2f xyz3 %.2f:%.2f:%.2f \
size1: %.2f size2: %.2f rgb %d:%d:%d\n",
		((t_fgr*)(prms->figures->content))->id,
		((t_fgr*)(prms->figures->content))->xyz1.x,
		((t_fgr*)(prms->figures->content))->xyz1.y, 
		((t_fgr*)(prms->figures->content))->xyz1.z,
		((t_fgr*)(prms->figures->content))->xyz2.x,
		((t_fgr*)(prms->figures->content))->xyz2.y, 
		((t_fgr*)(prms->figures->content))->xyz2.z,
		((t_fgr*)(prms->figures->content))->xyz3.x,
		((t_fgr*)(prms->figures->content))->xyz3.y, 
		((t_fgr*)(prms->figures->content))->xyz3.z,
		((t_fgr*)(prms->figures->content))->size1,
		((t_fgr*)(prms->figures->content))->size2,
		((t_fgr*)(prms->figures->content))->rgb.r,
		((t_fgr*)(prms->figures->content))->rgb.g, 
		((t_fgr*)(prms->figures->content))->rgb.b);
		prms->figures = prms->figures->next;
	}
	prms->figures = tmp;
}
